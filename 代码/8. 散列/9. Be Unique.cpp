#include <stdio.h>
#include<string.h>
int main()
{
    int N;
    scanf("%d", &N);
    int hashtable[10004];
    memset(hashtable, 0,sizeof(hashtable));
    int value[100005];
    for(int i =0; i< N;i++)
    {
        scanf("%d",&value[i]);
        hashtable[value[i]]++;
    }
    int i;
    for(i =0; i<N;i++)
    {
        if(hashtable[value[i]] == 1){

            break;
        }
    }
    if(i<N){
        printf("%d", value[i]);
    }else{
        printf("None");
    }


    return 0;
}
