#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct{
    char name[15];
    char id[15];
    int grade;
}Student;
Student student[105];
bool cmp(Student a, Student b);
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N;i++)
    {
        scanf("%s %s %d",student[i].name, student[i].id, &student[i].grade);
    }
    int Gmin,Gmax;
    scanf("%d %d", &Gmin,&Gmax);
    sort(student, student+N,cmp);

    int Count = 0;
    for(int i =0;i<N;i++)
    {
        if(student[i].grade>=Gmin && student[i].grade<=Gmax){
            printf("%s %s\n",student[i].name,student[i].id);
            Count++;
        }
    }
    if(Count == 0)
    {
        printf("NONE\n");
    }

}
bool cmp(Student a, Student b)
{
   if(a.grade != b.grade)   return a.grade > b.grade;
    return false;
}
