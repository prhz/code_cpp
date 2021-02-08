#include<stdio.h>
#include<utility>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        if(n == 0)
        {
            break;
        }
        for(int i = 0; i < n;i++){
            pair<double,double> point1, point2, point3;
            double x1,x2,x3,y1,y2,y3;
            scanf("%lf %lf", &x1, &y1);
            scanf("%lf %lf", &x2, &y2);
            scanf("%lf %lf", &x3, &y3);
            point1.first = x1;

            point1.second = y1;
            point2.first = x2;
            point2.second = y2;
            point3.first = x3;
            point3.second = y3;
            double x, y;
            x = (point1.first + point2.first + point3.first)/3.0;
            y = (point1.second + point2.second+point3.second)/3.0;
            printf("%.1f %.1f\n", x, y);
        }

    }



}
