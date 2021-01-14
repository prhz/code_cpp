#include <stdio.h>
typedef struct {
    int year;
    int month;
    int day;
}Date;
void printnextDate(Date date);
int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i< N;i++)
    {
        Date date;
        scanf("%d %d %d",&date.year, &date.month, &date.day);
        printnextDate(date);

    }
    return 0;
}
void printnextDate(Date date)
{
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(date.day + 1 > month[date.month-1])
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
    printf("%04d-%02d-%02d\n",date.year, date.month,date.day);
}
