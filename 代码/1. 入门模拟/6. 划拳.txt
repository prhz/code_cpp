#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int J_han, J_hua, Y_han, Y_hua;
	int J_count = 0;
	int Y_count = 0; 
	for(int i = 0; i < N; i++)
	{	
		scanf("%d %d %d %d", &J_han, &J_hua, &Y_han, &Y_hua);
		if(J_hua == J_han + Y_han && Y_hua != J_han + Y_han)//甲赢乙输
		{
			Y_count++;
		}else if(Y_hua == J_han + Y_han && J_hua != J_han + Y_han)
		{
			J_count++;
		}	
	}
	printf("%d %d\n", J_count, Y_count);
	return 0;
}
