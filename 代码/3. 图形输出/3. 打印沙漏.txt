#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    char c;
    scanf("%d %c", &N,&c);
    int x = (int)sqrt((N+1)*2.0) -1;
    if(x % 2 ==0){ // 偶数时 减一
        x--;
    }
    for(int i = x; i>=1; i-=2)
    {
        for(int j = 0; j < (x-i)/2;j++)
        {
            printf(" ");
        }
        for(int k = 0; k < i; k++)
        {
            printf("%c",c);
        }
        
        printf("\n");
    }
    for(int i = 3; i <= x; i+=2)
    {
         for(int j = 0; j < (x-i)/2;j++)
        {
            printf(" ");
        }
        for(int k = 0; k < i; k++)
        {
            printf("%c",c);
        }
        
        printf("\n");
    }
    int use = ((1+x)*(x+1))/2-1;
    printf("%d\n", N-use);


    return 0;
}
// 输出完*后，其他空格不用输出