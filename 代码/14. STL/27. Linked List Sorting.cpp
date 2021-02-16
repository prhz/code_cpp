#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct Node{
	int Address;
	int Data;
	int Next;
}Node;
bool cmp(Node a, Node b);
Node List[100002];
int main()
{
	int n, firstAddr;
	scanf("%d %d", &n, &firstAddr);
	vector<Node> vt;
	Node temp;
	for(int i = 0; i< n;i++)
	{
		scanf("%d %d %d", &temp.Address, &temp.Data, &temp.Next);
		List[temp.Address] = temp;
		
	}
	int count = 0;
	while(firstAddr != -1)
	{
		temp = List[firstAddr];
		vt.push_back(temp);
		count ++;
		firstAddr = List[firstAddr].Next;
	}
	if(vt.size()==0){
		printf("0 -1\n");
		return 0;
	}
	sort(vt.begin(), vt.end(), cmp);
	printf("%d %05d\n", count,vt[0].Address);
	int i;
	for(i=0;i<vt.size()-1;i++)
	{

		printf("%05d %d %05d\n", vt[i].Address, vt[i].Data, vt[i+1].Address);

	}
	printf("%05d %d -1\n", vt[i].Address, vt[i].Data);

	return 0;
}
bool cmp(Node a, Node b)
{
	return a.Data < b.Data;
}