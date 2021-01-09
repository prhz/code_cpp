#include <stdio.h>
typedef struct Poly{
    int exp;
    double cof;

}Poly;

int main()
{
    Poly p1[1005];
    double result[2010]={0}; // 保存结果
    int K1,K2;
    scanf("%d", &K1);
    for(int i = 0; i< K1;i++)
    {
        scanf("%d %lf", &p1[i].exp, &p1[i].cof);
    }
    scanf("%d", &K2);
    for(int i = 0; i< K2;i++)
    {
        int exp;
        double cof;

        scanf("%d %lf", &exp, &cof);
        for(int j = 0; j < K1; j ++)
        {
            result[exp+p1[j].exp] += cof*p1[j].cof;
        }

    }
    int count = 0;
    for(int i = 0; i<2010; i++)
    {
        if(result[i] != 0.0){
            count++;
        }

    }
    printf("%d", count);
    for(int i = 2010-1; i>=0; i--)
    {
        if(result[i]!=0.0){
            printf(" %d %.1lf", i, result[i]);
        }


    }

    return 0;
}
