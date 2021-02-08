#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

vector<int> courses[2505];
char name[40005][5];
bool compare(int a, int b);
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);

    for(int i = 0; i<N;i++)
    {
        int num;
        scanf("%s %d",name[i], &num);
        for(int j = 0; j< num;j++)
        {
            int c_id;
            scanf("%d",&c_id);
            courses[c_id].push_back(i);
        }
    }

    for(int i = 1; i<= K;i++)
    {
        printf("%d %d\n",i,courses[i].size());
        sort(courses[i].begin(),courses[i].end(),compare);
        for(int j = 0; j<courses[i].size();j++)
        {
            printf("%s\n",name[courses[i][j]]);
        }
    }
    return 0;
}
bool compare(int a, int b)
{

    return strcmp(name[a],name[b])<0;
}
