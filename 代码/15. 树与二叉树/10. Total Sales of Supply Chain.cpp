#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
typedef struct {
	int data;
	vector<int> childs;
}Tree;
Tree tree[100005];
double ans = 0;
double p, r;
void DFS(int index, int depth);
int main()
{
	int N;
	
	scanf("%d %lf %lf",&N, &p, &r);
	r /= 100;

	for(int i = 0; i< N; i++)
	{
		int k;
		scanf("%d", &k);
		if(k == 0){
			scanf("%d", &tree[i].data);
		}else{
			for(int j = 0; j< k; j++)
			{
				int cid;
				scanf("%d", &cid);
				tree[i].childs.push_back(cid);

			}
		}
	}
	

	DFS(0, 0);
	printf("%.1f\n", p*ans);


	return 0;
}
void DFS(int index, int depth)
{
	if(tree[index].childs.size() == 0){
		ans += tree[index].data * pow(1+r, depth);
	}
	for(int i = 0; i < tree[index].childs.size(); i++)
	{
		DFS(tree[index].childs[i], depth+1);
	}
}