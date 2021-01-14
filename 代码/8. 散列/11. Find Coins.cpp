#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int N,M;
    int hashtable[1005];// 1- 500
    memset(hashtable, 0, sizeof(hashtable));

    scanf("%d %d", &N,&M);
    int v;
    for(int i =0; i< N;i++)
    {
        scanf("%d", &v);
        hashtable[v] ++;
    }

    for(int i = 0; i<M;i++)
    {
        if(hashtable[i]&&hashtable[M-i]){
            if(i==M-i &&hashtable[i]<=1){
                continue;
            }
            printf("%d %d\n",i,M-i);
            return 0;
        }

    }

    printf("No Solution\n");

    return 0;
}
