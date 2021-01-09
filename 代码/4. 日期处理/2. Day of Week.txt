#include <stdio.h>
#include <string.h>
typedef struct{
    int year;
    int month;
    int day;
    int week;
}Date;
int Days(Date base, Date date);
char Week[7][15] = {"Monday", "Tuesday", "Wednesday","Thursday","Friday", "Saturday", "Sunday"};
int getMonth(char month[15]);
bool isLeapYear(int year);
int main()
{
    int day;
    char month[15];
    int year;
    Date base;
    base.year = 1000;
    base.month = 1;
    base.day = 1;
    base.week = 2;// 0-6
    while(scanf("%d %s %d", &day, month, &year)!=EOF)
    {
        Date date;
        date.year = year;
        date.month = getMonth(month);
        date.day = day;

        int days = Days(base, date);

        printf("%s\n", Week[(days+base.week)%7]);

    }
    return 0;
}
int Days(Date base, Date date)
{
    int days = 0;
    int month_leap[12] = {31,29, 31, 30,31,30, 31, 31,30,31,30,31};
    int month_notleap[12]={31,28, 31, 30,31,30, 31, 31,30,31,30,31};
    for(int y = base.year; y<date.year;y++)
    {
        if(isLeapYear(y))
        {
            days+= 366;
        }else{
            days+=365;
        }
    }
    for(int m = base.month; m < date.month; m++)
    {
        if(isLeapYear(date.year))
        {
            days+=month_leap[m-1];
        }else{
            days+=month_notleap[m-1];
        }
    }
    days+=date.day-base.day;
    return days;
}

int getMonth(char month[15])
{
    char Cmonth[12][15] = {"January","February","March", "April", "May", "June", "July", "August", "September","October","November", "December"};
    int i;
    for(i = 0; i < 12;i++)
    {
        if(strcmp(month, Cmonth[i]) == 0)
        {
            break;
        }
    }
    return i+1;
}
bool isLeapYear(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        return true;
    }
    return false;
}
