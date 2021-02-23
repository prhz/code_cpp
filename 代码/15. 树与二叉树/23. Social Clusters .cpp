#include <stdio.h>
#include <algorithm>
using namespace std;
int father[1005];
int isRoot[1005]={0};
int classes[1005]={0};
void init(int n);
int findFather(int x);
void Union(int a, int b);
bool cmp(int a, int b);
int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    int k;
    for(int i = 1; i<= n;i++){
        scanf("%d: ", &k);
        int h;
        for(int j = 0; j< k;j++)
        {
            scanf("%d", &h);
            if(classes[h] == 0){
                classes[h] = i; // 第一个有 h 爱好的人作为根
            }else{
                Union(i, classes[h]);
            }

        }
    }
    for(int i = 1; i<=n;i++)
    {
        isRoot[findFather(i)] ++;
    }

    int ans=0;
    for(int i= 1;i<=n;i++)
    {
        if(isRoot[i]>0){
            ans++;
        }
    }
    printf("%d\n", ans);
    sort(isRoot+1, isRoot+n+1,cmp);
    for(int i = 1; i <= ans; i++)
    {
        printf("%d", isRoot[i]);
        if(i<ans){
            printf(" ");
        }else{
            printf("\n");
        }
    }

    return 0;
}
void Union(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb){
        father[fa] = fb;
    }

}
void init(int n)
{
    for(int i = 1; i<= n; i++)
    {
        father[i] = i;
    }
}

int findFather(int x)
{
    int a = x;
    while(x != father[x]){
        x = father[x];
    }

    while(a!=father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
bool cmp(int a, int b)
{
    return a>b;
}