#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

typedef struct node{
	int data;
	node* lchild;
	node* rchild;
}*Node, *BTree;
int Value[80];
int n;
int count;
int mynext;
void PostOrder(BTree bt);

BTree CreateBT();
int main()
{
	memset(Value, -1, sizeof(Value));
	scanf("%d", &n);
	string temp;
	int v;
	for(int i = 0; i< 2*n; i++)
	{
		cin >> temp;
		if("Push" == temp)
		{
			cin >> v;
		}else if("Pop" == temp){
			v = -1;
		}
		Value[i] = v;
	}
	mynext = 0;
	BTree bt = CreateBT();
	count = 0;
	PostOrder(bt);

	return 0;
}

BTree CreateBT()
{
	// 递归出口
	if(Value[mynext] == -1)
	{
		mynext++;
		return NULL;
	}
	// 建根
	Node root = new node;

	root->data = Value[mynext];
	mynext++;
	// 建左子树
	root->lchild = CreateBT();
	// 建右子树
	root->rchild = CreateBT();
	return root;
}

void PostOrder(BTree bt)
{
	if(bt != NULL){
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);

		printf("%d", bt->data);
		count++;
		if(count < n){
			printf(" ");
		}
	}
	
}

