#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int year;
    int month;
    int day;
}Person;
bool IsMore(Person a, Person b);
bool Isless(Person a, Person b);
int main()
{
    Person temp;

    Person Left, Right;
    Left.year = 1814;
    Left.month = 9;
    Left.day = 5;
    Right.year = 2014;
    Right.month = 9;
    Right.day = 7;
    Person Max = Left;
    Person Min = Right;
    int N;
    int count = 0;
    scanf("%d", &N);
    for(int i = 0; i< N; i++)
    {
        scanf("%s %d/%d/%d",temp.name, &temp.year, &temp.month, &temp.day);
        if(IsMore(temp, Left)&&Isless(temp, Right))
        {
            count ++;
            if(IsMore(temp, Max)){
                Max = temp;
            }
            if(Isless(temp, Min)){
                Min = temp;
            }

        }
    }
    if(count == 0){printf("0\n");}
    else{
        printf("%d %s %s\n", count, Min.name, Max.name);
    }

    return 0;
}
bool Isless(Person a, Person b)
{
    if(a.year != b.year){
        return a.year < b.year;
    }else if(a.month != b.month){
        return a.month < b.month;
    }else if(a.day != b.day)
    {

        return a.day < b.day;
    }else{
        return false;
    }
}
bool IsMore(Person a, Person b)
{
    if(a.year!=b.year)
    {
        return a.year > b.year;
    }else if(a.month != b.month){
        return a.month > b.month;
    }else if(a.day!=b.day)
    {

        return a.day > b.day;
    }else{
        return false;
    }

}
