#include <stdio.h>

int main()
{
    long long A, B, C, result;
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%lld %lld %lld", &A,&B,&C);
        result = A+B;
        if(A>0 && B>0 && result<0){
            printf("Case #%d: true\n", i+1);
        }else if(A<0 && B<0 && result>=0){
            printf("Case #%d: false\n", i+1);
        }else if(result > C){
            printf("Case #%d: true\n", i+1);
        }else {
            printf("Case #%d: false\n", i+1);
        }
    }
    return 0;
}
