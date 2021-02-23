#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct Node{
    int data;
    int height; // 用于计算平衡因子
    Node* lchild;
    Node* rchild;
}Node, *AVLTree;
int getH(AVLTree tree);
int getBF(AVLTree tree);
AVLTree CreateAVL(int data[], int n);
void Insert(AVLTree &tree, int data);
Node* Search(AVLTree tree, int data);
void updateH(AVLTree &tree);
void R(AVLTree &root);
void L(AVLTree &root);
void InOrder(AVLTree tree);
int main()
{
    int n;
    scanf("%d", &n);
    int data[25];
    for(int i = 0; i< n;i++)
    {
        scanf("%d", &data[i]);
    }
    AVLTree tree = CreateAVL(data, n);
    printf("%d\n",tree->data);
    
    return 0;
}
AVLTree CreateAVL(int data[], int n)
{
    AVLTree tree = NULL;
    for(int i = 0; i < n;i++)
    {
        Insert(tree, data[i]);
    }
    return tree;
}
void Insert(AVLTree &tree, int data)
{
    if(tree == NULL)
    {   
        tree = new Node;
        tree->data = data;
        tree->lchild = tree->rchild = NULL;
        tree->height = 1;
        return ;
    }

    if(data < tree->data)
    {
        Insert(tree->lchild, data);
        updateH(tree);
        if(getBF(tree) == 2){
            if(getBF(tree->lchild)==1){
                // LL 右旋
                R(tree);
            }else if(getBF(tree->lchild)==-1){
                // LR 
                L(tree->lchild);
                R(tree);
            }

        }
    }else {
        Insert(tree->rchild, data);
        updateH(tree);
        if(getBF(tree) == -2){
            if(getBF(tree->rchild) == -1){
                // RR
                L(tree);
            }else if(getBF(tree->rchild) == 1){
                // RL
                R(tree->rchild);
                L(tree);
            }
        }
    }

}
Node* Search(AVLTree tree, int data)
{
    if(tree == NULL)
    {
        return NULL;
    }
    if(data == tree->data){
        return tree;
    }else if(data < tree->data){
        return Search(tree->lchild, data);
    }else{
        return Search(tree->rchild, data);
    }

}

void R(AVLTree &root)
{
    Node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateH(root);
    updateH(temp);
    root = temp;
}

void L(AVLTree &root)
{
    Node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;

    updateH(root);
    updateH(temp);
    root = temp;

}

void updateH(AVLTree &tree)
{
    tree->height = max(getH(tree->lchild), getH(tree->rchild)) + 1;
}


int getBF(AVLTree tree)
{
    return getH(tree->lchild) - getH(tree->rchild);
}

int getH(AVLTree tree)
{
    if(tree == NULL)
    {
        return 0;
    }else{
        return tree->height;
    }
}

void InOrder(AVLTree tree)
{

    if(tree == NULL){
       return;
    }
    InOrder(tree->lchild);
    printf("%d\n",tree->data);
    InOrder(tree->rchild);
}