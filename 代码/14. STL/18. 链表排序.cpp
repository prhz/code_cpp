#include <stdio.h>

using namespace std;
typedef struct Node{
	int id;
	int score;
	Node* next;
}Node, *LinkList;
LinkList CreateList(int n);
void PrintList(LinkList L);
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	LinkList L = CreateList(m+n);
	PrintList(L);
	return 0;
}

LinkList CreateList(int n)
{
	LinkList L = new Node;
	L->next = NULL;


	for(int i = 0; i < n; i++)
	{	
		Node* temp = new Node;
		scanf("%d %d", &temp->id, &temp->score);

		Node* node = L;
		while(node->next!=NULL && node->next->id < temp->id)
		{
			node = node->next;
		}
		temp->next = node->next;
		node->next = temp;


	}
	return L;

}
void PrintList(LinkList L)
{
	Node* node = L->next;
	while(node!=NULL)
	{
		printf("%d %d\n", node->id, node->score);
		node = node->next;
	}
}
