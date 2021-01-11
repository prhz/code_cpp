#include <stdio.h>

int main()

{
    int N;
    scanf("%d", &N);

    int B = N/100;
    int S = (N%100)/10;
    int G = N%10;

    for(int i = 0; i<B;i++)
    {
        printf("B");
    }
    for(int i = 0; i<S;i++)
    {
        printf("S");
    }
    for(int i = 0;i < G;i++)
    {

        printf("%d",i+1);
    }



    return 0;
}
