#include<stdio.h>
#include<string.h>

int main()
{
    int score[1005]; // 1 - 1000 有效
    memset(score, 0, sizeof(score));
    int N;
    scanf("%d", &N);
    int Did,Dyid,s;
    for(int i =0; i< N;i++)
    {
        scanf("%d-%d %d", &Did,&Dyid,&s);
        score[Did]+=s;
    }
    int index = 1;
    for(int i = 1; i<= 1000;i++)
    {
        if(score[i]>score[index])
        {
            index = i;
        }
    }
    printf("%d %d", index, score[index]);
    return 0;
}
