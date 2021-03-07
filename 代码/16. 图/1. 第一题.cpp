#include <stdio.h>
#include <vector>

using namespace std;
const int MaxN = 1000010;

vector<int> GraphAdj[MaxN];
bool visit[MaxN] = {false};
bool isExsit[MaxN] = {false};
void DFS(int vid, int depth);
void DFSTravel(int n);
int main()
{
    int i, j;
    int n = 0;
    while(scanf("%d %d", &i, &j)!=EOF)
    {
        GraphAdj[i].push_back(j);
        GraphAdj[j].push_back(i);
        isExsit[i] = isExsit[j] = true;
        if(i > n){
            n = i; 
        }
        if(j > n){
            n = j;
        }
    }

    DFSTravel(n);
    return 0;
}
void DFS(int vid, int depth)
{
    visit[vid] = true;

    for(int i = 0; i< GraphAdj[vid].size(); i++)
    {
        int v = GraphAdj[vid][i];
        if(visit[v]==false){
            DFS(v, depth+1);
        }
    }

}
void DFSTravel(int n)
{
    int count=0;
    for(int i = 0; i<= n; i++)
    {
        if(visit[i] == false && isExsit[i])
        {
            count ++;
            DFS(i, 1);
        }
    }
    printf("%d\n", count);
}