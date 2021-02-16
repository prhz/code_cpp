#include<stdio.h>
#include<queue>
using namespace std;

const int maxn = 1010;
typedef struct mouse
{
	int weight;
	int rank;
}mouse;
int main()
{
	mouse mouses[maxn];
	int np, ng, order;
	scanf("%d %d", &np, &ng);
	for(int i = 0; i < np; i++)
	{	
		scanf("%d", &mouses[i].weight);
	}
	queue<int> q;
	for(int i = 0; i<np;i++)
	{
		scanf("%d", &order);
		q.push(order);
	}
	int temp = np;
	int group;
	while(q.size() != 1){
		// 计算 group
		if(temp % ng == 0){
			group = temp / ng;
		}else{
			group = temp / ng + 1;
		}
		for(int i = 0; i< group; i++)
		{
			int k = q.front();
			for(int j = 0; j< ng; j++)
			{
				if(i*ng+j >= temp) break;
				int front = q.front();
				if(mouses[front].weight > mouses[k].weight)
				{
					k = front;
				}
				mouses[front].rank = group+1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mouses[q.front()].rank = 1;
	for(int i= 0; i< np; i++)
	{
		printf("%d", mouses[i].rank);
		if(i<np-1){
			printf(" ");
		}
	}
	return 0;
}

