#include <stdio.h>

typedef struct  Node
{
	int data;
	Node* next;
}Node, *LinkList;
LinkList CreateList(int n);
void Deal(LinkList &L);
void PrintList(LinkList L);
bool IsEmpty(LinkList L);
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		LinkList L = CreateList(n);
		
		
		if(IsEmpty(L)){
			printf("list is empty\n");
		}else{
			PrintList(L);
			Deal(L);
			PrintList(L);
		}
	}
}
void Deal(LinkList &L)
{
	
	Node* target = L->next;
	Node* node = NULL;
	if(target!=NULL){
		node = target->next;
	}
	while(node!=NULL)
	{
		if(target->data == node->data)
		{
			Node* denode = node;
			node = node->next;
			target->next = node;
			
			delete(denode);
		}else{
			target = node;
			node = node->next;
		}
	}
}

LinkList CreateList(int n)
{
	LinkList L = new Node;
	L->next = NULL;
	Node* pre = L;

	for (int i = 0; i < n; i++)
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
		if(count == 1)
		{
			printf("%d", node->data);
		}else{
			printf(" %d", node->data);
		}
		node = node->next;
	}
	printf("\n");
}
bool IsEmpty(LinkList L)
{
	if(L->next == NULL)
	{
		return true;
	}else{
		return false;
	}
}