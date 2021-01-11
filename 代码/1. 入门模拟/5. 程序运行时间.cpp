#include <stdio.h>
#include <math.h>
int main()
{
	long C1, C2;
	double CLK_TCK = 100;
	while(scanf("%ld %ld", &C1, &C2)!=EOF)
	{
		int cha = (int)((C2 - C1)/CLK_TCK + 0.5);
		int h = cha / 3600;
		int m = (cha %3600) / 60;
		int s = (cha %3600) % 60;
		
		printf("%02d:%02d:%02d\n", h, m, s);
	}

	return 0;
}
