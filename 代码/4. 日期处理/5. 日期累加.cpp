#include <stdio.h>
typedef struct {
    int year;
    int month;
    int day;
}Date;
int isLeapYear(int year);
void printnextDate(Date date, int days);
int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i< N;i++)
    {
        Date date;
        int days;
        scanf("%d %d %d %d",&date.year, &date.month, &date.day, &days);
        printnextDate(date, days);

    }
    return 0;
}
void printnextDate(Date date, int days)
{
    int month[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
                        {31,29,31,30,31,30,31,31,30,31,30,31}
                            };
    for(int i = 0; i< days;i++){

        if(date.day + 1 > month[isLeapYear(date.year)][date.month-1])
        {
            date.day = 1;
            if(date.month + 1>12)
            {
                date.month = 1;date.year++;
            }else{
                date.month++;
            }
        }else{
            date.day ++;
        }
    }
    printf("%04d-%02d-%02d\n",date.year, date.month,date.day);
}

int isLeapYear(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        return 1;
    }
    return 0;

}
