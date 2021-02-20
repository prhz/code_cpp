#include <stdio.h>
#include <math.h>
#include<vector>
using namespace std;
typedef struct {
	int data;
	vector<int> childs;
}Tree;
Tree tree[100005];
int minDepth=100000;
int Count=0;
void DFS(int index, int depth);
int main()
{	
	int N;
	double p, r;

	scanf("%d %lf %lf", &N, &p, &r);
	r /= 100;
	for(int i = 0; i < N;i++)
	{
		int num;
		scanf("%d", &num);

		for(int j = 0 ; j < num; j++)
		{
			int cid;
			scanf("%d", &cid);
			tree[i].childs.push_back(cid);
		}
	}
	DFS(0, 0);
	double ans = p* pow(1+r, minDepth);
	printf("%.4f %d\n", ans,Count);
	return 0;
}
void DFS(int index, int depth)
{
	if(tree[index].childs.size()==0)
	{
		if(depth < minDepth)
		{
			minDepth = depth;
			Count = 1;
		}else if(depth == minDepth)
		{
			Count ++;
		}else{
			return ;
		}
	}
	for(int i = 0; i < tree[index].childs.size();i++)
	{
		DFS(tree[index].childs[i], depth+1);
	}
}


