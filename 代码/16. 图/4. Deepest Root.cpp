#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
vector<int> GraphAdj[MAXN];
int visit[MAXN] = {false};
typedef struct Node
{
    int nid;
    int depth;
}NDepth;
NDepth ndepth[MAXN];
int Depth = 0;
bool cmp(NDepth a, NDepth b);
void InitVisit();
void DFS(int vid, int depth);
int DFSTravel(int n, int vid);
int N;
int main()
{
   
    scanf("%d", &N);
    int a, b;
    for(int i = 0; i< N-1; i++ )
    {
        scanf("%d %d", &a, &b);
        GraphAdj[a].push_back(b);
        GraphAdj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
    {
        InitVisit();
        Depth = 0;
        int ans = DFSTravel(N, i);
        
        if(ans > 1){
            printf("Error: %d components\n", ans);
            return 0;
        }else{
            ndepth[i].nid = i;
            ndepth[i].depth = Depth; 
        }
    }

    sort(ndepth+1, ndepth+N+1, cmp);
    int max = ndepth[1].depth;
    for(int i = 1; i <= N; i++){
        if(ndepth[i].depth == max){
            printf("%d\n", ndepth[i].nid);
        }else{
            break;
        }
    }

    return 0;
}
bool cmp(NDepth a, NDepth b)
{
    if(a.depth != b.depth){
        return a.depth > b.depth;
    }else{
        return a.nid < b.nid;
    }
}

void InitVisit()
{
    for(int i = 0; i < MAXN; i++)
    {
        visit[i] = false;  
    }
}
void DFS(int vid, int depth)
{
    if(depth >Depth){
        Depth = depth;
    }
    visit[vid] = true;
    for(int i = 0; i < GraphAdj[vid].size(); i++)
    {
        int v = GraphAdj[vid][i];
        if(visit[v] == false){
            DFS(v, depth+1);
        }
    }
}
int DFSTravel(int n, int vid)
{
    int count = 1;
    DFS(vid, 1);
    for(int i = 1; i<=N; i++){ 
        if(visit[i] == false){
            DFS(i, 1);
            count ++;
        }
    }
    return count;
}