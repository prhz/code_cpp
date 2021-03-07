#include <stdio.h>
#include <vector>
using namespace std;
const int MaxN = 1000;
bool visit[MaxN] = {false};
vector<int> GraphAdj[MaxN];
void initvisit();
void initvector();
void DFS(int vid, int depth);

int DFSTravel(int n);
int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        if(n == 0){
            break;
        }
        initvector();
        initvisit();
        for(int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            GraphAdj[x].push_back(y);
            GraphAdj[y].push_back(x);
        }
        int ans = DFSTravel(n);
        if(ans == 1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
void initvisit()
{
    for(int i = 0; i < MaxN; i++)
    {
        visit[i] = false;
    }
}
void initvector()
{
    for(int i = 0; i< MaxN; i++){
        GraphAdj[i].clear();
    }
}
void DFS(int vid, int depth)
{
    visit[vid] = true;
    for(int i = 0; i < GraphAdj[vid].size(); i++)
    {
        int v = GraphAdj[vid][i];
        if(visit[v] == false){
            DFS(v, depth+1);
        }
    }
}

int DFSTravel(int n)
{
    int count = 0;

    for(int i = 1; i<= n; i++)
    {
        if(visit[i] == false){
            DFS(i, 1);
            count++;
        }
    }

    return count;
}