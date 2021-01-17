#include<stdio.h>

int main()
{
    int n;

    while(scanf("%d", &n)!=-1)
    {
        double ans = 0.0;
        if(n == 0)  break;

        if(n<=4) ans = 10;
        if(n>4 && n<= 8) ans = 10+(n-4)*2;
        if(n>8)
        {
            while(n>8)
            {
                n= n-8;
                ans +=18;
            }
            if(n<=4)
            {
                ans+= n*2.4;
            }else{
                ans+=10+(n-4)*2;
            }
        }
        if(ans-(int)ans == 0){
            printf("%d\n",(int)ans);
        }else{
        printf("%.1f\n",ans);
        }
    }

    return 0;
}
