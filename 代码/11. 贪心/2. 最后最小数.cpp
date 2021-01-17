#include<stdio.h>

int main()
{
    int Count[10];
    for(int i = 0; i<10;i++)
    {
        scanf("%d", &Count[i]);
    }
    // 输出第一个最小的不为0的数
    for(int i =1; i< 10;i++)
    {
        if(Count[i]>0)
        {
            printf("%d",i);
            Count[i]--;
            break;
        }
    }
    // 输出其余的
    for(int i = 0; i< 10;i++)
    {
        for(int j = 0;j<Count[i];j++)
        {
            printf("%d",i);
        }
    }
    return 0;
}
