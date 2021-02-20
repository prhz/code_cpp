#include <stdio.h>
#include<vector>
using namespace std;
typedef struct {
	int data;
	vector<int> childs;
}Tree;
Tree tree[105];
int hashTable[105];
int maxDepth = 0;
void DFS(int index, int depth);
int main()
{	
	int N,M;
	scanf("%d %d",&N,&M);

	for(int i = 0; i < M; i++)
	{
		int pid, cid, num;
		scanf("%d %d", &pid, &num);
		for(int j = 0; j < num; j++)
		{
			scanf("%d", &cid);
			tree[pid].childs.push_back(cid);
		}

	}

	DFS(1, 0);
	for(int j = 0; j <= maxDepth; j++)
	{
		printf("%d", hashTable[j]);
		if(j < maxDepth){
			printf(" ");
		}else{
			printf("\n");
		}
	}

	return 0;
}

void DFS(int index, int depth)
{
	if(tree[index].childs.size() == 0)
	{
		hashTable[depth]++;
		if(depth > maxDepth)
		{
			maxDepth = depth;
		}
		return ;
	}

	for(int i = 0; i < tree[index].childs.size();i++)
	{
		DFS(tree[index].childs[i], depth+1);
	}
}



