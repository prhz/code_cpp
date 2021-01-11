#include<stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	long long A, B, C;
	for(int i = 0; i < T; i++)
	{
		scanf("%lld %lld %lld", &A, &B, &C);
		if((A+B)>C)
		{
			printf("Case #%d: true\n", i+1);
		}else{
			printf("Case #%d: false\n", i+1);
		}
	
	}

	return 0;
}