#include<stdio.h>
const int MAX_SIZE = 1005;
int main()
{
    double P1[MAX_SIZE] = {0};
    double P2[MAX_SIZE] = {0};
    double PS[MAX_SIZE] = {0};
    int K;
    scanf("%d", &K);
    for(int i = 0 ; i < K; i++)
    {
        int index;
        double value;
        scanf("%d %lf", &index, &value);
        P1[index] += value;
    }

    scanf("%d", &K);
    for(int i = 0 ; i < K; i++)
    {
        int index;
        double value;
        scanf("%d %lf", &index, &value);
        P2[index] += value;
    }
    int count = 0;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        PS[i] = P1[i] + P2[i];
        if(PS[i]!=0){
            count ++;
        }
    }
    printf("%d", count);
    for(int i = MAX_SIZE-1; i>=0; i--)
    {
        if(PS[i] != 0)
        {
            printf(" %d %.1lf", i, PS[i]);
        }
    }

}
