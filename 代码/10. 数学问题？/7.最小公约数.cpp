#include<stdio.h>
int gcd(int a, int b);
int lcm(int a, int b);
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
        int y = lcm(m,n);
        printf("%d\n",y);
    }

    return 0;
}
int lcm(int a, int b)
{
    int y;
    int g = gcd(a, b);
    y = a/g*b;
    return y;
}

int gcd(int a, int b)
{
    if(b==0) return a;
    else    return gcd(b, a%b);
}


——————————————————————————————————————


#include<stdio.h>
int gcd(int a, int b);
int lcm(int a, int b);
int main()
{
    int s;
    int num[100];
    scanf("%d", &s);
    for(int i = 0; i<s;i++)
    {
        int m;
        scanf("%d", &m);
        for(int j=0; j<m;j++)
        {
            scanf("%d", &num[j]);
        }
        int result = num[0];
        for(int j=1;j<m;j++)
        {
            result = lcm(result, num[j]);
        }
        printf("%d\n",result);
    }


    return 0;
}
int lcm(int a, int b)
{
    int y;
    int g = gcd(a, b);
    y = a/g*b;
    return y;
}

int gcd(int a, int b)
{
    if(b==0) return a;
    else    return gcd(b, a%b);
}

