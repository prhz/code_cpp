#include <stdio.h>

typedef struct Node{
	int data;
	Node* next;
}Node, *LinkList;
LinkList CreateList(int n);
void PrintList(LinkList L);
void Deal(LinkList &L, int x);
int main()
{
	int x, n;
	scanf("%d", &x);
	scanf("%d", &n);
	LinkList L = CreateList(n);
	Deal(L, x);

	return 0;
}
void Deal(LinkList &L, int x)
{
	Node* node = L;
	while(node->next!=NULL && node->next->data < x)
	{
		node = node->next;
	}
	if(node->next!=NULL && node->next->data == x)
	{
		
		node = node->next;
		node->data = node->next->data;
		node->next->data = x;
		printf("相同元素为：%d\n", x);
		printf("交换后的链表为：");
		PrintList(L);

	}else{

		Node* n = new Node;
		n->data = x;
		n->next = node->next;
		node->next = n;
		printf("no\n");
		PrintList(L);
	}


}
LinkList CreateList(int n)
{
	LinkList L = new Node;
	L->next = NULL;
	 // 尾插法
	Node* pre = L;
	for(int i = 0; i< n;i++)
	{
		Node* node = new Node;

		scanf("%d", &node->data);
		node->next = pre->next;
		pre->next = node;
		pre = node;
	}
	return L;
}
void PrintList(LinkList L)
{
	Node* node = L->next;
	int count = 0;
	while(node!=NULL)
	{
		count++;
		if(count==1)
		{
			printf("%d", node->data);
		}else{
			printf(" %d", node->data);
		}
		
		node = node->next;
	}
	printf("\n");
}