#include <stdio.h>

typedef struct {
    int year;
    int month;
    int day;
}Date;
bool isLeapYear(int year);
int Days(Date Maxdate1, Date Mindate2);
int main()
{

    Date Mindate1, Maxdate2;
    int date1, date2;
    while(scanf("%d%d", &date1, &date2)!=EOF)
    {
        if(date2 < date1){
            int temp = date2;
            date2 = date1;
            date1 = temp;
        }
        Maxdate2.year = date2 / 10000;
        Maxdate2.month = (date2%10000)/100;
        Maxdate2.day =  (date2%10000)%100;

        Mindate1.year = date1 / 10000;
        Mindate1.month = (date1%10000)/100;
        Mindate1.day =  (date1%10000)%100;

        Date base = Mindate1;
        base.month = 1;
        base.day = 1;
        int days1 = Days(base, Mindate1);
        int days2 = Days(base, Maxdate2);

        printf("%d\n", days2 - days1+1);
    }

    return 0;
}
int Days(Date Basedate1, Date Maxdate2)
{
     int MisLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     int MisNotLeap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     int days= 0;
     for(int y = Basedate1.year; y<Maxdate2.year;y++)
     {
         if(isLeapYear(y))
         {
             days+=366;
         }else{
            days+=365;
         }
     }
     for(int m = Basedate1.month;m<Maxdate2.month;m++)
     {
         if(isLeapYear(Maxdate2.year))
         {
             days+=MisLeap[m-1];
         }else{
            days+=MisNotLeap[m-1];
         }
     }
     days+=Maxdate2.day-Basedate1.day+1;
     return days;
}
bool isLeapYear(int year)
{
    if((year%4==0&&year%100!=0) ||year%400==0){
        return true;
    }
    return false;
}
