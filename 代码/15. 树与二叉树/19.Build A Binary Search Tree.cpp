#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct BSTNode{
    int data;
    int lchild;
    int rchild;
}BSTree;
void LevelOrder(int root);
void InOrder(int root);
BSTree tree[105];
int KEY[105];
int num;
int n;
int c;
int main()
{

    scanf("%d", &n);
    int lc,rc;
    for(int i = 0; i < n;i++)
    {
        scanf("%d %d", &lc, &rc);
        tree[i].lchild = lc;
        tree[i].rchild = rc;
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &KEY[i]);
    }
    sort(KEY, KEY + n);
    num = 0;
    InOrder(0);
    c = 0;
    LevelOrder(0);
    return 0;
}

void InOrder(int root)
{
    if(root == -1)
    {
        return ;
    }
    InOrder(tree[root].lchild);
    tree[root].data = KEY[num++];
    
    InOrder(tree[root].rchild);
}
void LevelOrder(int root)
{
    queue<int> q;
    q.push(root);

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        printf("%d", tree[now].data);
        c++;
        if(c<n)
        {
            printf(" ");
        }else{
            printf("\n");
        }
        if(tree[now].lchild != -1)
        {
            q.push(tree[now].lchild);
        }
        if(tree[now].rchild != -1)
        {
            q.push(tree[now].rchild);
        }
    }

}