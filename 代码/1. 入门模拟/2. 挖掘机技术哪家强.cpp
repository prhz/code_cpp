#include <stdio.h>

const int MAXSIZE = 10005;
int school[MAXSIZE] = {0};

int main()
{
	int N;
	scanf("%d", &N);
	int id, score;

	for(int i = 0; i < N; i++) // 构建数组
	{
		scanf("%d %d", &id, &score);
		school[id] += score;
	}

	// 查找最大
	int max_id = -1, max_score = -1;
	for(i = 0; i < N; i++)
	{
		if(school[i] > max_score){
			max_score = school[i];
			max_id = i;
		}
	}
	printf("%d %d\n", max_id, max_score);
	return 0;
}