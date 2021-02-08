#include <stdio.h>

typedef struct Node
{
	int data;
	Node* next;
	
}Node, *LinkCList;
LinkCList CreateCList(int n);
void PrintCList(LinkCList L);
void Merge(LinkCList &L1, LinkCList &L2);
int main()
{
	int m, n;
	scanf("%d", &m);
	LinkCList L1 = CreateCList(m);
	
	scanf("%d", &n);
	LinkCList L2 = CreateCList(n);
	
	Merge(L1, L2);
	PrintCList(L1);

}
LinkCList CreateCList(int n)
{
	LinkCList L = new Node;
	L->next = L; // 循环链表初始化
    // 尾插法
    Node* pre = L;
	for(int i = 0; i< n; i++)
	{
		Node* node = new Node;
		scanf("%d", &node->data);
		node->next = L;
		pre->next = node;
		pre = node;
	}
	return L;
}
void PrintCList(LinkCList L)
{
	Node* node = L->next;
	int count = 0;
	while(node != L)
	{
		count ++;
		if(count == 1){
			printf("%d", node->data);
		}else{
			printf(" %d", node->data);
		}
		node = node -> next;
	}
	printf("\n");
}
void Merge(LinkCList &L1, LinkCList &L2)
{
	Node* head1 = L1;
	Node* head2 = L2;

	Node* node = L1;
	while(node->next!=L1)
	{
		node = node->next;
	}
	node->next = L2->next;
	
	while(node->next!=L2)
	{
		node = node->next;
	}
	node->next = L1;

}