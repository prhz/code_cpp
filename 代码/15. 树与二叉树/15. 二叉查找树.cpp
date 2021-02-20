#include <stdio.h>

typedef struct BSTNode{
    int data;
    BSTNode* lchild;
    BSTNode* rchild;
}BSTNode, *BSTree;

void PostOrder(BSTree tree);
void InOrder(BSTree tree);
void PreOrder(BSTree tree);
bool InsertNode(BSTree &tree, int x);
void CreateBST(BSTree &tree, int data[], int n);
int main()
{
   
    int Array[105];
    int n;
    while(scanf("%d", &n)!= -1)
    {
        BSTree tree;
        for(int i = 0; i < n;i++)
        {
            scanf("%d", &Array[i]);
        }
        CreateBST(tree, Array, n);
        PreOrder(tree);
        printf("\n");
        InOrder(tree);
        printf("\n");
        PostOrder(tree);
        printf("\n");
    }
    
    return 0;
}
void CreateBST(BSTree &tree, int data[], int n)
{
    tree = NULL;
    int i = 0;
    while(i < n)
    {
        InsertNode(tree, data[i]);
        i++;
    }
}

bool InsertNode(BSTree &T, int x)
{// 此处 & 很重要，因为插入前 T == NULL, 插入后，T 指向了一个新的结点
    if(T == NULL)// 查找失败，也即插入的位置
    {
        T = new BSTNode;
        T->data = x;
        T->lchild = NULL;
        T->rchild = NULL;
        return true; // 插入成功
    }
    else if(x == T->data){
       return false;
    }else if(x < T->data){
        return InsertNode(T->lchild, x);
    }else{
        return InsertNode(T->rchild, x);
    }
}
void PreOrder(BSTree tree)
{
    if(tree != NULL)
    {
        printf("%d ", tree->data);
        PreOrder(tree->lchild);
        PreOrder(tree->rchild);
    }
}

void InOrder(BSTree tree)
{
    if(tree != NULL)
    {
        InOrder(tree->lchild);
        printf("%d ", tree->data);
        InOrder(tree->rchild);
    }
}
void PostOrder(BSTree tree)
{
    if(tree != NULL)
    {
        PostOrder(tree->lchild);
        PostOrder(tree->rchild);
        printf("%d ", tree->data);
    }
}