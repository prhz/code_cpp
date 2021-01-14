#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct{
    char name[10];
    int age;
    int net_worth;
}Richest;
Richest richest[100005];

bool cmp(Richest a, Richest b);
int main()
{
    int N;
    int query;
    int Amin, Amax;
    scanf("%d %d",&N,&query);

    for(int i = 0; i< N;i++)
    {
        scanf("%s %d %d", richest[i].name, &richest[i].age, &richest[i].net_worth);
    }
    int M;
    sort(richest, richest+N,cmp);
    for(int i = 0; i< query;i++)
    {
        scanf("%d %d %d", &M, &Amin,&Amax);
        printf("Case #%d:\n", i+1);
        

        int printnum = 0;
        for(int j = 0; j<N&&printnum < M;j++)
        {
            if(richest[j].age >= Amin &&richest[j].age<= Amax){
                printf("%s %d %d\n",richest[j].name, richest[j].age,richest[j].net_worth);
                printnum++;
            }

        }
        if(printnum==0){
            printf("None\n");
        }

    }
    return 0;
}
bool cmp(Richest a, Richest b)
{
    if(a.net_worth!=b.net_worth){
        return a.net_worth > b.net_worth;
    }else if(a.age!=b.age){
        return a.age < b.age;
    }else {
        return strcmp(a.name, b.name)<0;
    }
}
// 优化

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct{
    char name[10];
    int age;
    int net_worth;
}Richest;
Richest richest[100005];
Richest richest100[100005];

bool cmp(Richest a, Richest b);
int main()
{
    int N;
    int query;
    int Amin, Amax;
    scanf("%d %d",&N,&query);

    for(int i = 0; i< N;i++)
    {
        scanf("%s %d %d", richest[i].name, &richest[i].age, &richest[i].net_worth);
    }
    int M;
    sort(richest, richest+N,cmp);
    int validnum=0;
    int Age[220] = {0};
    for(int i = 0; i<N;i++)
    {
        if(Age[richest[i].age]<100){
            Age[richest[i].age] ++;
            richest100[validnum++] = richest[i];
        }

    }
    for(int i = 0; i< query;i++)
    {
        scanf("%d %d %d", &M, &Amin,&Amax);
        printf("Case #%d:\n", i+1);


        int printnum = 0;
        for(int j = 0; j<validnum&&printnum < M;j++)
        {
            if(richest100[j].age >= Amin &&richest100[j].age<= Amax){
                printf("%s %d %d\n",richest100[j].name, richest100[j].age,richest100[j].net_worth);
                printnum++;
            }

        }
        if(printnum==0){
            printf("None\n");
        }

    }
    return 0;
}
bool cmp(Richest a, Richest b)
{
    if(a.net_worth!=b.net_worth){
        return a.net_worth > b.net_worth;
    }else if(a.age!=b.age){
        return a.age < b.age;
    }else {
        return strcmp(a.name, b.name)<0;
    }
}
