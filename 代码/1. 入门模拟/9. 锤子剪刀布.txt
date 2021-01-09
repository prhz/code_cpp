#include <stdio.h>
int Win(char a, char b);
int change(char a);
int main()
{
	int N;
	scanf("%d", &N);
	int J_BCJ[3] = {0}; // 各个姿势获胜次数
	int Y_BCJ[3] = {0};
	int J_WEF[3] = {0};
	int Y_WEF[3] = {0};
	for(int i = 0; i < N; i++)
	{
		getchar(); // 吸收回车
		char J,Y;
		scanf("%c %c", &J, &Y);
		if(Win(J, Y) == 1)// 甲胜
		{
			int index_J = change(J);
			J_BCJ[index_J] ++;

			J_WEF[0] ++;
			Y_WEF[2] ++;
		}else if(Win(J, Y) == -1) // 乙胜
		{
			int index_Y = change(Y);
			Y_BCJ[index_Y] ++;
			
			J_WEF[2] ++;
			Y_WEF[0] ++;		
		}else{ // 平局
			J_WEF[1] ++;
			Y_WEF[1] ++;
		}
	
	}
	
	char map[3] = {'B', 'C', 'J'};
	int maxJ=-1, maxJ_index = -1;
	int maxY=-1, maxY_index = -1;
	for(i = 0; i < 3; i++)
	{
		if(maxJ < J_BCJ[i])
		{
			maxJ = J_BCJ[i];
			maxJ_index = i;
		}
		
	}
	for(i = 0; i < 3; i++)
	{
		if(maxY < Y_BCJ[i])
		{
			maxY = Y_BCJ[i];
			maxY_index = i;
		}
		
	}
	printf("%d %d %d\n", J_WEF[0], J_WEF[1], J_WEF[2]);
	printf("%d %d %d\n", Y_WEF[0], Y_WEF[1], Y_WEF[2]);
	printf("%c %c\n", map[maxJ_index], map[maxY_index]);
	
	return 0;
}
int change(char a)
{
	if(a == 'B'){
		return 0;
	}else if(a == 'C'){
		return 1;
	}else if( a == 'J'){
		return 2;
	}else{
		return -1;
	}
}
// BCJ
int Win(char a, char b)
{
	if(a == b){
		return 0;
	}
	else if((a == 'B' && b == 'C') || (a == 'C' && b == 'J') || (a == 'J' && b == 'B'))
	{
		return 1;
	}else{
		return -1;
	}
	
}
