#include <stdio.h>

int main()
{
    char s[3] = {'W', 'T','L'};
    double result = 1;
    for(int i = 0; i< 3;i++)
    {
        double temp;
        double max = 0;
        int index = -1;
        for(int j = 0; j < 3;j++)
        {
            scanf("%lf", &temp);
            if(max<temp){
                max = temp;
                index = j;
            }
        }
         printf("%c ",s[index]);
        result *= max;
    }
    printf("%.2f\n",(result*0.65-1)*2);

    return 0;
}
