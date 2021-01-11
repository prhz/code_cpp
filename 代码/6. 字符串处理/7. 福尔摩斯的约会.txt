#include<stdio.h>
#include<string.h>
char Week[7][5] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
    char str1[66];
    char str2[66];
    char str3[66];
    char str4[66];
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    scanf("%s", str4);
    int len = strlen(str1) < strlen(str2)?strlen(str1):strlen(str2);
    int day = 0;
    int i;
    for(i = 0; i<len;i++)
    {
        if((str1[i] == str2[i])&&(str1[i]>='A' && str1[i]<='G'))
        {
            day = str1[i] - 'A';
            break;
        }
    }
    int h;
    for(i++;i<len;i++)
    {
        if(str1[i] == str2[i])
        {
            if(str1[i]>='0' && str1[i]<='9'){
                h = str1[i] - '0';
                break;
            }else if(str1[i]>='A' && str1[i]<='N'){
                h = str1[i] -'A' +9+1;
                break;
            }
        }
    }
    len = strlen(str3) < strlen(str4)?strlen(str3):strlen(str4);
    int mi;
    for(int i = 0; i<len;i++)
    {
        if((str3[i]==str4[i])&&((str3[i]>='A' &&str3[i]<='Z')||(str3[i]>='a' &&str3[i]<='z'))){
           mi = i;
           break;
        }
    }
    printf("%s %02d:%02d\n",Week[day],h,mi);



}
