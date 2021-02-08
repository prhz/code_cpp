#include <stdio.h>

typedef struct Node{
	int data;
	Node* next;
}Node, *LinkList;
LinkList CreateList(int n);
LinkList ReverseList(LinkList L);
bool IsEmpty(LinkList L);
void PrintList(LinkList L);
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
	
		LinkList L = CreateList(n);
		LinkList NL = ReverseList(L);
		PrintList(L);
		if(!IsEmpty(L)){
			PrintList(NL);
		}
	}
	


}

LinkList CreateList(int n)
{
	// 尾插发
	LinkList L = new Node;
	L->next = NULL;
	Node* pre = L;
	for(int i = 0; i< n; i++)
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
		count ++;
		if(count == 1){
			printf("%d", node->data);

		}else{
			printf(" %d", node->data);
		}
		node = node->next;
	}
	if(count == 0)
	{
		printf("list is empty");
	}
	printf("\n");
}
LinkList ReverseList(LinkList L)
{
	LinkList NL = new Node;
	NL->next = NULL;

	Node* node = L->next;
	while(node!=NULL)
	{
		Node* nnode = new Node;
		nnode->data = node->data;
		nnode->next = NL->next;
		NL->next = nnode;

		node = node->next;
	}
	return NL;	

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