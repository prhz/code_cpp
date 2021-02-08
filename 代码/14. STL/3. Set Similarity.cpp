#include<stdio.h>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
    int N;
    set<int> myset[52];

    scanf("%d", &N);
    //处理输入
    for(int i = 1; i<= N;i++)
    {
        int num;
        scanf("%d", &num);
        for(int j = 0; j < num; j++)
        {
            int x;
            scanf("%d",&x);
            myset[i].insert(x);
        }
    }
    int query;
    scanf("%d", &query);

    for(int i = 0; i<query;i++)
    {
        int a, b;
        set<int> temp;
        scanf("%d %d", &a, &b);
        int size1 = myset[a].size();
        int size2 = myset[b].size();
        set_union(myset[a].begin(),myset[a].end(),myset[b].begin(),myset[b].end(),inserter(temp,temp.begin()));
        int all = temp.size();
        printf("%.1f%%\n",100.0*(size1+size2-all)/all);
    }

    return 0;
}
