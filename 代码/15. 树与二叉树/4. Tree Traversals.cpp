#include <stdio.h>
#include <queue>
using namespace std;
typedef struct node{
	int data;
	node* lchild;
	node* rchild;
}*Node, *BTree;

int PostSeq[35];
int InSeq[35];

int n;
int count;
void LayerOrder(BTree bt);
BTree CreateBTByPostIn(int postL, int postR, int inL, int inR);
int main()
{
	
	scanf("%d", &n);
	for(int i= 0; i< n; i++)
	{
		scanf("%d", &PostSeq[i]);
	}
	for(int i = 0; i< n; i++)
	{
		scanf("%d", &InSeq[i]);
	}

	// 根据后序，中序进行建树，并进行层序遍历 

	BTree bt = CreateBTByPostIn(0, n-1, 0, n-1);

	count = 0;
	LayerOrder(bt);
	
	return 0;
}



BTree CreateBTByPostIn(int postL, int postR, int inL, int inR)
{
	// 递归出口
	if(postL > postR){
		return NULL;
	}

	// 建根
	Node root = new node;
	root->data = PostSeq[postR];

	int k;
	for(k = inL; k <= inR; k++)
	{
		if(PostSeq[postR] == InSeq[k])
		{
			break;
		}
	}
	int numLeft = k - inL;	

	// 建右子树
	root->rchild = CreateBTByPostIn(postL+numLeft, postR-1, k+1, inR);

	// 建左子树
	root->lchild = CreateBTByPostIn(postL,postL+numLeft-1 , inL, k-1);

	return root;

}

void LayerOrder(BTree bt)
{
	
	queue<Node> q;
	q.push(bt);

	while(!q.empty())
	{
		Node now = q.front();
		q.pop();
		printf("%d", now->data);
		count++;
		if(count <= n-1){
			printf(" ");
		}else{
			printf("\n");
		}

		if(now->lchild != NULL){
			q.push(now->lchild);
		}
		if(now->rchild != NULL){
			q.push(now->rchild);
		}
	}
}
