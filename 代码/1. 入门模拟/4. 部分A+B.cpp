#include <stdio.h>

int main()
{
	long A, B;
	int DA, DB;
	
	while(scanf("%ld %d %ld %d", &A, &DA, &B, &DB)!= EOF)
	{
		long PA = 0, PB = 0;
		// 处理 PA
		while(A!=0)
		{
			if((A%10) == DA)
			{
				PA = PA*10 + DA;
			}
			A = A/10;
		}
		// 处理 PB
		while(B!=0)
		{
			if((B%10) == DB)
			{
				PB = PB*10 + DB;
			}
			B = B/10;
		}
		printf("%ld\n", PA+PB);
	}

	
	return 0;
}