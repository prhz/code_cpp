#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct{
    double kucun;
    double danjia;
}YueBing;
bool cmp(YueBing a, YueBing b);
int main()
{
    YueBing yuebing[1005];
    int N;
    double D;
    scanf("%d %lf",&N,&D);
    for(int i = 0; i<N;i++)
    {
        scanf("%lf", &yuebing[i].kucun);
    }
    double sum;
    for(int i = 0; i<N;i++)
    {
        scanf("%lf",&sum);
        yuebing[i].danjia = sum/yuebing[i].kucun;
    }
    sort(yuebing, yuebing+N,cmp);

    double xiaoshouE=0.0;
    for(int i = 0; i< N;i++)
    {
        if(yuebing[i].kucun >= D){
            xiaoshouE += D*yuebing[i].danjia;
            yuebing[i].kucun -=D;
            break;
        }else {
            xiaoshouE += yuebing[i].kucun * yuebing[i].danjia;
            D-=yuebing[i].kucun;
            yuebing[i].kucun = 0;
        }
    }
    printf("%.2f",xiaoshouE);
    return 0;
}
bool cmp(YueBing a, YueBing b)
{
    return a.danjia>b.danjia;
}
