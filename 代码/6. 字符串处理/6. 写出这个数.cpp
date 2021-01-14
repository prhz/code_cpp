#include<stdio.h>
#include<string.h>

int main()
{
    char mapstr[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    char numbers[106];
    scanf("%s", numbers);
    int len = strlen(numbers);
    int sum=0;
    for(int i =0; i<len;i++)
    {
        sum+=numbers[i]-'0';
    }
    char strsum[10];
    sprintf(strsum,"%d",sum);
    for(int i = 0;i<strlen(strsum);i++)
    {
        printf("%s",mapstr[strsum[i]-'0']);
        if(i<strlen(strsum)-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    return 0;
}
