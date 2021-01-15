#include<stdio.h>
int Count(int i, int sum);
int n;
int value[30];
int main()
{
    while(scanf("%d",&n)!=-1)
    {
        for(int i =0;i<n;i++)
        {
            scanf("%d",&value[i]);
        }
        int count = Count(0,40);
        printf("%d\n",count);
    }


    return 0;
}

int Count(int i, int sum)
{
    if(sum == 0)    return 1;
    else if(i == n || sum<0)    return 0;
    else return Count(i+1, sum) + Count(i+1, sum-value[i]);

}
