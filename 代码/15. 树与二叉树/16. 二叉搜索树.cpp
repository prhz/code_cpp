#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct BSTNode{
    int data;
    BSTNode* lchild;
    BSTNode* rchild;
}BSTNode, *BSTree;
bool isEqual(int Array1[], int Array2[], int n);
void PostOrder(BSTree tree);
void PreOrder(BSTree tree);
void PreOrder(BSTree tree);
bool InsertNode(BSTree &tree, int x);
void CreateBST(BSTree &tree, int data[], int n);
int PreOrderSEQ[15];
int TEMP[15];
int inde=0;
int main()
{
   
    int Array[15];
    int n;
    while(scanf("%d", &n)!= -1)
    {
        
        if(n == 0)
        {
            break;
        }
        getchar();
        char str[15];
        BSTree tree;
        gets(str);
        for(int i= 0; i< strlen(str);i++)
        {
            Array[i] = str[i] - '0';
        }
        CreateBST(tree, Array, strlen(str));
        inde = 0;
        PreOrder(tree);
        for(int i =0; i< strlen(str);i++)
        {
            PreOrderSEQ[i] = TEMP[i];
        }

        for(int i = 0; i < n; i++)
        {
            gets(str);
            for(int i= 0; i< strlen(str);i++)
            {
                Array[i] = str[i] - '0';
            }
            CreateBST(tree, Array, strlen(str));
            inde = 0;
            PreOrder(tree);
            // for(int i =0; i< strlen(str);i++)
            // {
            //     printf("%d\n", TEMP[i]);
            // }
            bool flag = isEqual(PreOrderSEQ, TEMP, strlen(str));
            if(flag){
                printf("YES\n");
            }else{
                printf("NO\n");
            }


        }
        
        
    }
    
    return 0;
}
bool isEqual(int Array1[], int Array2[], int n)
{
    for(int i = 0; i<n;i++)
    {
        if(Array1[i] != Array2[i])
        {
            return false;
        }
    }
    return true;
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
        TEMP[inde++] = tree->data;
        //printf("%d ", tree->data);
        PreOrder(tree->lchild);
        
        PreOrder(tree->rchild);
    }
}
