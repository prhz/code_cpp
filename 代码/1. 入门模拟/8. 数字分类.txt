#include <stdio.h>

int main()
{
	int N;
	while(scanf("%d", &N)!=EOF)
	{
		int count[5] = {0};
		int ans[5] = {0};
		int val;
		for(int i = 0; i< N; i++)
		{
			scanf("%d", &val);
			if(val%5 == 0)
			{
				if(val%2==0){
					ans[0] += val;
					count[0]++;
				}
				
			}else if(val%5 == 1)
			{
				if(count[1]%2==0){
					ans[1] += val;
				}else{
					ans[1] += -1 * val;
				} 
				count[1]++;
			}else if(val%5 == 2)
			{
				count[2]++;
				ans[2] = count[2];
			
			}else if(val%5 == 3)
			{
				count[3]++;
				ans[3] += val;
			}else if(val%5 == 4)
			{
				if(ans[4]<val)
				{
					ans[4] = val;
				}
				count[4]++;
			}
		}
		if(count[0] > 0){
			printf("%d ", ans[0]);
		}else{
			printf("N ");
		}
		if(count[1] > 0)
		{
			printf("%d ", ans[1]);
		}else{
			printf("N ");
		}
		if(count[2] > 0)
		{
			printf("%d ", ans[2]);
		}else{
			printf("N ");
		}
		if(count[3] > 0)
		{
			printf("%.1f ", 1.0 * ans[3]/count[3]);
		}else{
			printf("N ");
		}
		if(count[4] > 0)
		{
			printf("%d\n", ans[4]);
		}else{
			printf("N\n");
		}

	}



	return 0;
}