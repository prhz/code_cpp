#include <stdio.h>

#include<vector>
using namespace std;
typedef struct {
	int data;
	vector<int> childs;
}Tree;
Tree tree[105];
int hashTable[105] = {0};
void DFS(int index, int depth);
int main()
{	
	
	int N,M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i< M; i++)
	{
		int pid,cid, num;
		scanf("%d %d", &pid, &num);

		for(int j = 0; j< num;j++)
		{
			scanf("%d", &cid);
			tree[pid].childs.push_back(cid);
		}

	}
	DFS(1, 1);
	int d , num = 0;
	for(int i = 1; i < 103; i++)
	{
		if(hashTable[i] > num)
		{
			num = hashTable[i];
			d = i;
		}
	}
	printf("%d %d\n", num, d);
	return 0;
}
void DFS(int index, int depth)
{
	hashTable[depth]++;
	// 边界
	for(int i = 0; i<tree[index].childs.size();i++)
	{
		DFS(tree[index].childs[i], depth+1);
	}

}
