#include<stdio.h>
int Eat(int n);
int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        int count = Eat(n);
        printf("%d\n",count);
    }
}
int Eat(int n)
{
    if(n == 1)  return 1;
    if(n == 2)  return 2;
    return Eat(n-1) + Eat(n-2);
}
