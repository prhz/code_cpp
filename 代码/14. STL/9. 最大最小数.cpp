#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[10010];
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d %d\n", a[n-1], a[0]);
    }
    return 0;
}