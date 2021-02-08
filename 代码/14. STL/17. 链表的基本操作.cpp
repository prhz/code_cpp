#include <stdio.h>
#include <string.h>

using namespace std;
#define ElemType int 
typedef struct Node
{
	ElemType data; 
	Node *next;

}Node, *LinkList;

bool GetElem(LinkList L, int pos, ElemType &elem);
bool InsertElem(LinkList &L, int pos, ElemType elem);
bool DeleteElem(LinkList &L, int pos, ElemType &elem);
LinkList CreateListHead(int n);
LinkList CreateListRear(int n);
void PrintList(LinkList L);

int GetSize(LinkList L);
bool IsEmpty(LinkList L);



int main()
{
	int n;
	scanf("%d", &n);
	LinkList L =  CreateListHead(n);
	int m;
	scanf("%d", &m);
	char keyword[10];
	for(int i = 0; i<m;i++)
	{
		scanf("%s", keyword);
		if(strcmp(keyword,"show") == 0)
		{
			PrintList(L);
		}else if(strcmp(keyword ,"delete")== 0){
			int pos, value;
			scanf("%d", &pos);
			if(DeleteElem(L, pos, value))
			{
				printf("delete OK\n");
			}else{
				printf("delete fail\n");
			}
		}else if(strcmp(keyword ,"insert") == 0){
			int pos, elem;
			scanf("%d%d", &pos, &elem);
			if(InsertElem(L, pos, elem)){
				printf("insert OK\n");
			}else{
				printf("insert fail\n");
			}
		}else if(strcmp(keyword,"get") == 0){
			int pos, value;
			scanf("%d", &pos);
			if(GetElem(L, pos, value))
			{
				printf("%d\n", value);
			}
		}
	}


	return 0;
}

LinkList CreateListHead(int n)
{
	// 头插法
	LinkList L;
	L = new Node;
	L->next = NULL; // 初始化头结点

	for(int i = 0; i< n; i++)
	{
		Node* node = new Node;

		scanf("%d", &node->data);
		node->next = L->next;
		L->next = node;
	}
	return L;
}
LinkList CreateListRear(int n)
{
	// 尾插法
	LinkList L;
	L = new Node;
	L->next = NULL;

	Node *pre;
	pre = L;
	for(int i = 0; i < n; i++)
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
	Node *node;
	int count = 0;
	node = L->next;
	if(node == NULL)
	{
		printf("Link list is empty\n");
	}else{
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
		printf("\n");

	}

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
int GetSize(LinkList L)
{
	int count = 0;
	Node* node = L->next;
	while(node!=NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}
bool GetElem(LinkList L, int pos, ElemType &elem)
{
	Node* node = L->next;
	int j = 1;
	while(node!=NULL && j < pos)
	{	
		node = node->next;
		j++;
	}
	if(node==NULL || j > pos)
	{
		return false;
	}
	elem = node->data;
	return true;
}

bool InsertElem(LinkList &L, int pos, ElemType elem)
{
	Node *node = L;
	int j = 0;
	while(node!=NULL && j < pos-1){

		node = node->next;
		j++;
	}
	if(node == NULL || j > pos-1){
		return false;
	}
	Node* newNode = new Node;
	newNode->data = elem;
	newNode->next = node->next;
	node->next = newNode;
	return true;
}
bool DeleteElem(LinkList &L, int pos, ElemType &elem)
{
	Node *node = L;
	int j = 0;
	while(node->next!=NULL && j < pos-1){

		node = node->next;
		j++;
	}
	if(node->next == NULL || j > pos-1){
		return false;
	}
	Node *deNode = node->next;
	node->next = deNode->next;

	elem = deNode->data;
	delete(deNode);
	return true;

}