#include <stdio.h>
#include <string.h>
typedef struct node
{
	char data;
	node* lchild;
	node* rchild;

} *Node, *BTree;

char preSeq[1003], inSeq[1003];
void PostOrder(BTree bt);
BTree CreateBTByPreAndIn(int PreL, int PreR, int InL, int InR);
int main()
{
	
	while(scanf("%s %s", preSeq, inSeq)!=EOF){
		BTree bt = CreateBTByPreAndIn(0, strlen(preSeq)-1, 0, strlen(inSeq)-1);
		PostOrder(bt);
		printf("\n");
	}

	return 0;
}

BTree CreateBTByPreAndIn(int PreL, int PreR, int InL, int InR)
{
	// 递归出口
	if(PreL > PreR){
		return NULL;
	}

	BTree root = new node;
	root->data = preSeq[PreL];

	// 查询根结点在 中序序列的位置

	int k;

	for(k = InL; k <= InR; k++)
	{
		if(preSeq[PreL] == inSeq[k]){
			break;
		}
	}

	int numLeft = k - InL;

	// 
	root->lchild = CreateBTByPreAndIn(PreL+1, PreL+numLeft, InL, k-1);



	root->rchild = CreateBTByPreAndIn(PreL+numLeft+1, PreR, k+1, InR);



	return root;
}

void PostOrder(BTree bt)
{
	if(bt != NULL){
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%c", bt->data);
	}
}

