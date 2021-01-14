#include<stdio.h>
#include<string.h>
int main()
{
    int hashTable[101];
    memset(hashTable,0,sizeof(hashTable));
    int N;
    scanf("%d", &N);
    int temp;
    for(int i = 0; i< N;i++)
    {
        scanf("%d",&temp);
        hashTable[temp] ++;
    }
    int K;
    scanf("%d",&K);

    int score;
    for(int i = 0; i< K;i++)
    {
        scanf("%d",&score);
        printf("%d",hashTable[score]);
        if(i<K-1)
        {
            printf(" ");
        }
    }


    return 0;
}
