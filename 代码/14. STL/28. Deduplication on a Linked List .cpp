#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct Node{
	int Address;
	int Data;
	int Next;
}Node;

Node List[100003];
bool Array[10005];
int main()
{
	int firstAddr, n;
	scanf("%d %d", &firstAddr, &n);

	Node temp;
	for(int i = 0; i< n;i++)
	{
		scanf("%d %d %d", &temp.Address, &temp.Data, &temp.Next);
		List[temp.Address] = temp;
	}
	vector<Node> vt1, vt2;
	int addr = firstAddr;
	while(addr != -1){
		int value = List[addr].Data;
		if(!Array[abs(value)]){
			vt1.push_back(List[addr]);
			Array[abs(value)] = true;
		}else{
			vt2.push_back(List[addr]);
		}
		addr = List[addr].Next;
	}
	int i;
	for(i=0; i< vt1.size()-1;i++){
		printf("%05d %d %05d\n", vt1[i].Address, vt1[i].Data, vt1[i+1].Address);

	}
	printf("%05d %d -1\n", vt1[i].Address, vt1[i].Data);

	if(vt2.size()>0)
	{

	
		for(i=0; i< vt2.size()-1;i++){
			printf("%05d %d %05d\n", vt2[i].Address, vt2[i].Data, vt2[i+1].Address);

		}
		printf("%05d %d -1\n", vt2[i].Address, vt2[i].Data);
	}
	
}