#include<stdio.h>

int main()
{
    int now = 0;
    int N;
    scanf("%d", &N);
    int next;
    int sum = 0;
    for(int i = 0; i< N;i++)
    {

        scanf("%d", &next);
        if(next>now){
            sum+=6*(next-now);
        }else{
            sum+=4*(now-next);
        }
        sum+=5;
        now = next;
    }

    printf("%d",sum);
}
