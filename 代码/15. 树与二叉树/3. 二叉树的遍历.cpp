#include <stdio.h>
typedef struct node
{
	char data;
	node* lchild;
	node* rchild;
}*Node, *BTree;

char preSeq[110];
BTree Create();
void Inorder(BTree bt);
int i;
int main()
{
	while(scanf("%s", preSeq)!=EOF){
		i = 0;
		BTree bt = Create();

		Inorder(bt);
		printf("\n");
	}
	return 0;
}

BTree Create()
{
	BTree root;
	
	
	if(preSeq[i] == '#'){
		i++;
		root = NULL;
	}else{
		root = new node;
		root->data = preSeq[i];
		i++;
		root->lchild = Create();
		root->rchild = Create();
	}
	return root;
}

void Inorder(BTree bt)
{
	if(bt != NULL){
		Inorder(bt->lchild);
		printf("%c ", bt->data);
		Inorder(bt->rchild);
	}
}
