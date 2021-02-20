#include <stdio.h>

typedef struct BSTNode{
    int data;
    BSTNode * lchild;
    BSTNode * rchild;
}BSTNode, *BSTree;
int n;
int Array[1005];
int TEMP[1005];
int POST[1005];
int num;
bool isEqual(int Array1[], int Array2[], int n);
void PreOrder(BSTree tree);
void PostOrder(BSTree tree);
void CreateBSTv1(BSTree &tree, int data[], int n);
void CreateBSTv2(BSTree &tree, int data[], int n);
bool InsertNodev1(BSTree &tree, int x);
bool InsertNodev2(BSTree &tree, int x);
int main()
{   
    scanf("%d", &n);
    for(int i =0; i< n;i++)
    {
        scanf("%d", &Array[i]);
    }
    BSTree ptree, imgtree;
    CreateBSTv1(ptree, Array, n);
    CreateBSTv2(imgtree, Array, n);

    num=0;
    PreOrder(ptree);
    bool flag1 = isEqual(Array, TEMP, n);
    num=0;
    PreOrder(imgtree);
    bool flag2 = isEqual(Array, TEMP, n);

    if(flag1){
        printf("YES\n");
        num = 0;
        PostOrder(ptree);
        for(int i = 0; i<n;i++)
        {
            printf("%d", POST[i]);
            if(i<n-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }else if(flag2){
        printf("YES\n");
        num = 0;
        PostOrder(imgtree);
        for(int i = 0; i<n;i++)
        {
            printf("%d", POST[i]);
            if(i<n-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
    else{
        printf("NO\n");
    }


    return 0;
}
bool isEqual(int Array1[], int Array2[], int n)
{
    for(int i = 0; i < n;i++)
    {
        if(Array1[i]!= Array2[i])
        {
            return false;
        }
    }
    return true;
}
void PreOrder(BSTree tree)
{
    if(tree!=NULL)
    {
        TEMP[num++] = tree->data;
        PreOrder(tree->lchild);
        PreOrder(tree->rchild);
    }
}
void PostOrder(BSTree tree)
{
    if(tree != NULL)
    {
        PostOrder(tree->lchild);
        PostOrder(tree->rchild);
        POST[num++] = tree->data;

    }
}
void CreateBSTv1(BSTree &tree, int data[], int n)
{
    tree = NULL;
    int i = 0;
     while(i<n)
     {
        InsertNodev1(tree, data[i]);
        i++;
     }
}
void CreateBSTv2(BSTree &tree, int data[], int n)
{
    tree = NULL;
    int i = 0;
    while(i<n)
    {
        InsertNodev2(tree, data[i]);
        i++;
    }
}

bool InsertNodev1(BSTree &tree, int x)
{
    if(tree == NULL)
    {
        tree = new BSTNode;
        tree->data = x;
        tree->lchild = NULL;
        tree->rchild = NULL;
        return true;
    }else if(x < tree->data){
        return InsertNodev1(tree->lchild, x);
    }else{ // x >= tree->data
        return InsertNodev1(tree->rchild, x);
    }
}

bool InsertNodev2(BSTree &tree, int x)
{
    if(tree == NULL)
    {
        tree = new BSTNode;
        tree->data = x;
        tree->lchild = NULL;
        tree->rchild = NULL;
        return true;
    }else if(x >= tree->data){
        return InsertNodev2(tree->lchild, x);
    }else{ // x < tree->data
        return InsertNodev2(tree->rchild, x);
    }
}

