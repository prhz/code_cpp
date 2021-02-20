#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
typedef struct {
	int data;
	vector<int> childs;
}Tree;
Tree tree[100005];
int maxDepth = 0;
int maxCount = 0;

void DFS(int index, int depth);
int main()
{
	int N; 
	double p, r;

	scanf("%d %lf %lf", &N, &p, &r);
	r /= 100;

	int root;
	for(int i = 0; i< N;i++)
	{
		int pid;
		scanf("%d",&pid);
		tree[i].data = i;
		if(pid == -1){
			root = i;		
		}
		else{
			tree[pid].childs.push_back(i);
		}
	}
	DFS(root, 0);
	double ans = p * pow(1+r, maxDepth);
	printf("%.2f %d\n", ans, maxCount);
	return 0;
}
void DFS(int index, int depth)
{	
	if(tree[index].childs.size() == 0) // 如果是叶子结点
	{
		if(depth > maxDepth){
			maxDepth = depth;
			maxCount = 1;
		}else if(depth == maxDepth){
			maxCount++;
		}
		return ;
	}
	for(int i = 0; i< tree[index].childs.size(); i++)
	{
		DFS(tree[index].childs[i], depth+1);
	}

}