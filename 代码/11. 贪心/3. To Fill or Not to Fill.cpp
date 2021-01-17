#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct{
    double price;
    double distance;
}Station;
#define INF 1000000;
bool cmp(Station a, Station b);
int main()
{
    Station station[505];
    double tank_capcity;
    double distance;
    double avg_distance;
    int stationN;
    // 处理输入
    scanf("%lf %lf %lf %d",&tank_capcity, &distance, &avg_distance,&stationN);
    for(int i = 0; i< stationN;i++)
    {
        scanf("%lf %lf",&station[i].price,&station[i].distance);
    }
    station[stationN].price = 0;
    station[stationN].distance = distance;
    int dis = tank_capcity * avg_distance;
    double cheapest = 0.0;

    int now = 0;

    sort(station,station+stationN,cmp);

    if(station[0].distance != 0){
        printf("The maximum travel distance = 0.00\n");
    }else{
        now = 0;

        double now_tank = 0.0;

        while(now<stationN){
            double MinPrice = INF;
            int next=-1;
            // 寻找下一个加油站
            for(int i = now+1;i<=stationN;i++)
            {
                if(station[i].distance <=(station[now].distance+dis)){
                    if(MinPrice > station[i].price)
                    {
                        MinPrice = station[i].price;
                        next = i;
                        if(station[now].price > MinPrice){
                            break;
                        }
                    }

                }
            }
            if(next==-1) break; // 满油状态下无法找到下一站
            double need = (station[next].distance - station[now].distance)/avg_distance;
            if(MinPrice < station[now].price)
            {
                if(now_tank < need)
                {
                    cheapest += (need - now_tank)*station[now].price;
                    now_tank = 0;
                }else{
                    now_tank -= need;
                }
            }else{
                cheapest += (tank_capcity - now_tank)*station[now].price;
                now_tank = tank_capcity - need;
            }

            now = next;

        }
        //printf("%d\n",now);
        if(now == stationN)
        {
            printf("%.2f",cheapest);
        }else{
            printf("The maximum travel distance = %.2f",station[now].distance+dis);
        }

    }
    return 0;
}

bool cmp(Station a,Station b)
{
    return a.distance<b.distance;

}
