#include <stdio.h>

bool isLeapYear(int year);
int main()
{
    int month_Leap[13] = {0, 31,60,91,121,152,182,213,244,274,305,335,366};
    int month_NotLeap[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};

    int year, days;
    while(scanf("%d %d", &year,&days)!=EOF)
    {
        int month;
        int day;
        if(isLeapYear(year))
        {

            for(int i = 0; i <13;i++)
            {
                if(days<=month_Leap[i])
                {
                    month = i;
                    break;
                }
            }
            day = days-month_Leap[month-1];

        }else{
            for(int i = 0; i <13;i++)
            {
                if(days<=month_NotLeap[i])
                {
                    month = i;
                    break;
                }
            }
            day = days-month_NotLeap[month-1];
        }
        printf("%04d-%02d-%02d\n",year,month,day);

    }

    return 0;
}

bool isLeapYear(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        return true;
    }
    return false;
}
