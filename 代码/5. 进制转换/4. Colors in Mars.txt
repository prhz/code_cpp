#include<stdio.h>

int main()
{
    char SS[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    int RD,GD,BD;
    scanf("%d %d %d",&RD, &GD,&BD);

    printf("#");
    printf("%c%c",SS[RD/13],SS[RD%13]);
    printf("%c%c",SS[GD/13],SS[GD%13]);
    printf("%c%c",SS[BD/13],SS[BD%13]);
    printf("\n");


    return 0;
}
