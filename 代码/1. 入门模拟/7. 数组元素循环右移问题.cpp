#include <stdio.h>
#include <string.h>
int main()
{
	int Array[105];
	int N, M;
	while(scanf("%d %d", &N, &M)!=EOF)
	{
		memset(Array, 0, sizeof(Array));
        M = M%N;
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &Array[i]);
		}
		for(int i = N-M; i < N; i++)
		{
			printf("%d ", Array[i]);
		}
		for(int i = 0; i < N-M; i++)
		{
			printf("%d", Array[i]);
			if(i < N-M-1){
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}
	return 0;
}