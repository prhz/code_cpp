#include<stdio.h>
int gcd(int a, int b);
int main()
{
    int m, n;
    while(scanf("%d %d",&m, &n)!=-1)
    {
        if(n > m){
            int temp = m;
            m = n;
            n = temp;
        }
        int g = gcd(m,n);
        printf("%d\n",g);
    }

    return 0;
}

int gcd(int a, int b)
{
    if(b==0) return a;
    else    return gcd(b, a%b);
}
