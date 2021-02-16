#include<stdio.h>
#include<vector>

using namespace std;
typedef struct Node{
	int address;
	char c;
	int next;
	int flag;
}Node;

int main()
{
	Node seq[100003];

	int begin1, begin2, n;
	scanf("%d %d %d", &begin1, &begin2, &n);

	int temp_addr, temp_next;
	char temp_data;
	for(int i = 0; i < n;i++)
	{
		scanf("%d %c %d", &temp_addr, &temp_data, &temp_next);
		seq[temp_addr].address = temp_addr;
		seq[temp_addr].c = temp_data;
		seq[temp_addr].next = temp_next;
		seq[temp_addr].flag = 0;
	}


	int addr = begin1;

	while(addr != -1)
	{
		seq[addr].flag ++;

		addr = seq[addr].next;

	}

	addr = begin2;
	while(addr != -1)
	{
		if(seq[addr].flag == 1){
			 printf("%05d\n", seq[addr].address);
			 return 0;
		}
		addr = seq[addr].next;
	}
	
	printf("-1\n");

	return 0;
}