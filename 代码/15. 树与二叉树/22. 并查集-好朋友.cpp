#include <stdio.h>
int father[105];
bool isRoot[105];
void init(int n);
void Union(int a, int b);
int findFather(int x);
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    init(n);
    int a, b;
    for(int i = 0; i<m;i++)
    {
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    for(int i = 1; i <= n;i++)
    {
        isRoot[findFather(i)] = true;
    }
    int ans = 0;
    for(int i = 1; i<=n;i++){
        ans+=isRoot[i];
    }
    printf("%d\n", ans);

    return 0;
}

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        father[i] = i;
        isRoot[i] = false;
    }
}
void Union(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb){
        father[fa] = fb;
    }
}

int findFather(int x)
{
    int a = x;
    while(x!=father[x]){
        x = father[x];
    }

    while(a!=father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}