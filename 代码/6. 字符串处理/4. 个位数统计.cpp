#include <stdio.h>
#include <string.h>

int main()
{
    char number[1005];
    scanf("%s", number); // 输入

    int countD[10] = {0};
    int len = strlen(number);

    for(int i = 0; i< len;i++)
    {
        countD[number[i]-'0']++;
    }
    // 输出

    for(int i = 0;i<10;i++)
    {
        if(countD[i]>0)
        {
            printf("%d:%d\n", i,countD[i]);
        }
    }


    return 0;
}
