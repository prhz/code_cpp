#include <stdio.h>
#include <queue>

using namespace std;
typedef struct node{
	int data;
	int lchild;
	int rchild;
}BTree;
int findroot();
BTree bt[30];
int count;
bool ischild[30] = {false};
void Inorder(int root);
void Layer(int root);
void Invert(int root);
int n;

int main()
{
	
	scanf("%d", &n);
	getchar();
	char temp1, temp2;
	for(int i = 0; i < n; i++)
	{

		scanf("%c %c", &temp1, &temp2);
		getchar();
		bt[i].data = i;
		if(temp1 == '-')
		{
			bt[i].lchild = -1;
		}else{
			bt[i].lchild = temp1 - '0';
			ischild[bt[i].lchild] = true;
		}
		if(temp2 == '-'){
			bt[i].rchild = -1;

		}else{
			bt[i].rchild = temp2 - '0';
			ischild[bt[i].rchild] = true;
		}
	}

	int root = findroot();
	Invert(root);
	count = 0;
	Layer(root);
	count = 0;
	Inorder(root);

	return 0;


}

int findroot()
{
	int i;
	for(i = 0; i< n;i++)
	{
		if(ischild[i] == false)
		{
			break;
		}
	}
	return i;
}


void Inorder(int root)
{
	if(root == -1)
	{
		return ;
	}
	Inorder(bt[root].lchild);
	printf("%d", bt[root].data);
	count ++;
	if(count < n)
	{
		printf(" ");
	}else{
		printf("\n");
	}
	Inorder(bt[root].rchild);
}

void Layer(int root)
{
	queue<int> q;
	q.push(root);

	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d", bt[now].data);
		count ++;
		if(count < n)
		{
			printf(" ");
		}else{
			printf("\n");
		}
		if(bt[now].lchild != -1)
		{
			q.push(bt[now].lchild);
		}
		if(bt[now].rchild != -1)
		{
			q.push(bt[now].rchild);
		}
	}
}

void Invert(int root)
{
	if(root == -1)
	{
		return ;
	}
	Invert(bt[root].lchild);
	Invert(bt[root].rchild);

	swap(bt[root].lchild, bt[root].rchild);

}