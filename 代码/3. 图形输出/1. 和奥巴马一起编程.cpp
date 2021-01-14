#include<stdio.h>
#include<math.h>

int main()
{
    int N;
    char c;
    scanf("%d %c",&N,&c);
    int hang = round(N/2.0);
    for(int i =0;i<N;i++)
    {
        printf("%c",c);
    }
    printf("\n");
    for(int i = 0; i<hang-2;i++)
    {
        printf("%c",c);
        for(int i = 0; i < N-2;i++)
        {
            printf(" ");
        }
        printf("%c\n",c);
    }

    for(int i =0;i<N;i++)
    {
        printf("%c",c);
    }
    printf("\n");
    return 0;
}
