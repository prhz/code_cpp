#include <stdio.h>

int main()
{
	char SHCDJ[5] = {'S', 'H', 'C', 'D', 'J'};
	int oldA[54] = {0};
	int nextA[54] = {0};
	int endA[54] = {0};
	int K;
	scanf("%d", &K);
	// 初始化oldA[54];
	for(int i = 0; i < 54; i++)
	{
		oldA[i] = i;
	}
	// 接受次序
	for(int i = 0; i< 54; i++)
	{
		scanf("%d", &nextA[i]);
	}
	// 计算 endA
	for(int j = 0; j < K; j++) // K轮次
	{
		for(int i= 0; i < 54; i++){
			endA[nextA[i]-1] = oldA[i];
		}
		// 更新 old
		for(int i = 0; i< 54; i++)
		{
			oldA[i] = endA[i];
		}
	}
	// 输出结果
	for(int i = 0; i< 54; i++)
	{
		printf("%c%d", SHCDJ[endA[i]/13], endA[i]%13+1);

		if(i < 53)
		{
			printf(" ");
		}else{
			printf("\n");
		}	
	}
	
	return 0;
}