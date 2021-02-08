#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 26*26*26*10+1;
vector<int> selectCoures[M];
int getId(char name[]);
int main()
{


    int N,K;
    scanf("%d %d", &N,&K);
    // 处理输入
    for(int i = 0; i< K;i++)
    {
        int c_id;
        int count;
        scanf("%d %d",&c_id, &count);
        char name_temp[10];
        for(int j = 0; j< count;j++)
        {
            scanf("%s",name_temp);
            int id = getId(name_temp);
            selectCoures[id].push_back(c_id);
        }
    }


    // 处理查询
    char query[10];
    for(int i = 0; i< N;i++)
    {
        scanf("%s", query);
        int id = getId(query);
        int size = selectCoures[id].size();
        sort(selectCoures[id].begin(), selectCoures[id].end());

        printf("%s %d",query,size);
        for(int j = 0; j<size; j++)
        {
            printf(" %d",selectCoures[id][j]);
        }
        printf("\n");
    }


}

int getId(char name[])
{
    int id = 0;
    for(int i = 0; i< 3;i++)
    {
        id = id*26+(name[i] - 'A');
    }
    id = id*10+(name[3]-'0');
    return id;
}
