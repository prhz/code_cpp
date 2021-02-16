#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef struct {
    int data;
    int level;
    vector<int> child;
}Tree;
int LayerOrder(int root);
Tree tree[105];
int main()
{
    int n;
    scanf("%d", &n);
   
    int p, c;

    while(scanf("%d %d", &p, &c)!=EOF){
       tree[p].child.push_back(c);
    }

    
    // 层次遍历
    int high = LayerOrder(1);
    printf("%d\n", high);
    return 0;
}

int LayerOrder(int root)
{
    int max = 1;
    queue<int> q;
    tree[root].level = 1;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();


        for(int j = 0; j < tree[now].child.size(); j++)
        {
            int id = tree[now].child[j];
            tree[id].level = tree[now].level+1;
            if(tree[id].level > max){
                max = tree[id].level;
            }
            q.push(id);
        }
        
    }

    return max;
}