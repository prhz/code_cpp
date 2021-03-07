#include <stdio.h>
#include <vector>

using namespace std;
const int MAXN = 1005;
vector<int> GraphAdj[MAXN];
bool visit[MAXN] = {false};
bool isExist[MAXN] = {false}; 
void DFS(int vid, int depth);
int DFSTravel(int n);
void Initvisit();
int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i <= N; i++)
    {
        isExist[i] = true;
    }
    int a, b;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        
        GraphAdj[a].push_back(b);
        GraphAdj[b].push_back(a);
    }
    for(int i = 0; i < K; i++)
    {
        Initvisit();
        int temp;
        scanf("%d", &temp);
        isExist[temp] = false;
        int count = DFSTravel(N);
        printf("%d\n", count-1);
        isExist[temp] = true;
    }

    return 0;
}
void Initvisit()
{
    for(int i = 0; i < MAXN; i++)
    {
        visit[i] = false;
    }
}
int DFSTravel(int n)
{
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == false && isExist[i] == true){
            DFS(i, 1);
            count ++;
        }
    }
    return count;
}
void DFS(int vid, int depth)
{
    visit[vid] = true;
    for(int i = 0; i< GraphAdj[vid].size(); i++)
    {
        int v = GraphAdj[vid][i];
        if(visit[v] == false && isExist[v] == true){
            DFS(v, depth+1);
        }
    }
}