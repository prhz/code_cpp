#include <stdio.h>
int Distance[100005];
int SumArray[100005];
int main()
{
	int N;

	int sum = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &Distance[i]);
		sum += Distance[i];
		SumArray[i] = sum;
	}
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
	{
		int left, right;
		scanf("%d %d", &left, &right);
		if(left > right)
		{
			int temp = left;
			left = right;
			right = temp;
		}
		int dis = SumArray[right-1] - SumArray[left-1];
		dis = dis < sum -dis ? dis : sum -dis;
		printf("%d\n", dis);
	}

	return 0;
}
