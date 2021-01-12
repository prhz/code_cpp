#include<stdio.h>
#include<string.h>

int main()
{
    int a, b;
    scanf("%d %d",&a,&b);
    int sum = a+b;
    if(sum<0){
        printf("-");
        sum = -sum;
    }
    char str_sum[35];
    sprintf(str_sum,"%d",sum);
    int i;
    for(i = 0;i<strlen(str_sum)%3;i++)
    {
        printf("%c", str_sum[i]);
    }
    if(strlen(str_sum)%3>0 &&strlen(str_sum)>3){
        printf(",");
    }

    int count = 0;
    for(; i<strlen(str_sum);i++)
    {
        printf("%c",str_sum[i]);
        count++;
        if(count%3==0&&i<strlen(str_sum)-1){
            printf(",");
        }

    }

    return 0;
}
