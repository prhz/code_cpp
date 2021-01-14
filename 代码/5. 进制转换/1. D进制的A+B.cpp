#include <stdio.h>

int main()
{
    int A,B,D;
    scanf("%d %d %d", &A,&B,&D);
    int sum = A+B;

    // sum -> D;
    int result[40];
    int num=0;
    do{
        result[num++] = sum%D;
        sum = sum/D;

    }while(sum!=0);
    for(int i = num-1;i>=0;i--)
    {
        printf("%d",result[i]);
    }
    printf("\n");
    return 0;
}
