#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct {
    int parent;
    int data;
    int weight;
    int sumw;
    vector<int> childs;
    vector<int> pathw;
}Tree;
Tree tree[105];
bool cmp(vector<int> v1, vector<int> v2);
void LayerOrder(int S);
int main()
{
    int N, M, S;
    scanf("%d %d %d", &N, &M, &S);
    for(int i = 0; i < N; i++)
    {
        tree[i].data = i;
        scanf("%d", &tree[i].weight);
    }
    for(int i = 0; i< M; i++)
    {
        int pid, num;
        scanf("%d %d", &pid, &num);
        int cid;
        for(int j = 0; j < num; j++)
        {
            
            scanf("%d", &cid);
            tree[pid].childs.push_back(cid);
            tree[cid].parent = pid;
        }
    }
    LayerOrder(S);
    

}

void LayerOrder(int S)
{
    int root = 0;
    vector<int> Leaf;
    tree[root].sumw = tree[root].weight;
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        // 访问
        if(tree[now].childs.size()==0 && tree[now].sumw == S){
            Leaf.push_back(now);
        }
        for(int i = 0; i< tree[now].childs.size(); i++)
        {
            int x = tree[now].childs[i];
            tree[x].sumw = tree[now].sumw + tree[x].weight;
            q.push(x);
        }
    }
    vector<int> Paths[100];
    for(int i = 0; i < Leaf.size(); i++){
        int node = Leaf[i];
        while(node!=0){
            Paths[i].push_back(tree[node].weight);
            node = tree[node].parent;
        }
        Paths[i].push_back(tree[0].weight);
    }

    for(int i = 0; i < Leaf.size(); i++){

        reverse(Paths[i].begin(), Paths[i].end());
    }
    
    sort(Paths, Paths + Leaf.size(),cmp);

    for(int i = 0; i < Leaf.size(); i++){
        for(int j = 0; j < Paths[i].size(); j++)
        {
            printf("%d", Paths[i][j]);
            if(j < Paths[i].size() - 1){
                printf(" ");
            }
        }
        printf("\n");
    }

}

bool cmp(vector<int> v1, vector<int> v2)
{
    vector<int>::iterator it1,it2;
    
    for(it1 = v1.begin(), it2 = v2.begin(); it1 != v1.end() && it2 != v2.end(); it1 ++, it2++)
    {
        if(*it1 != *it2){
            return *it1 > *it2;
        }
        
    }
    if(it1==v1.end()){
        return false;
    }
    if(it2 == v2.end())
    {
        return false;
    }
    return false;
}