#include <stdio.h>
#include <algorithm>
using namespace std;
typedef struct{
    int id;
    int score[4]; //ACME
}Student;
int Rank[1000000][4] = {0}; // 记录每个学生的等级
Student student[2005];
int now;
bool cmp(Student a, Student b);
int main()
{
    int N;//输入学生总数
    int M;// 查询人数
    // 处理输入
    scanf("%d %d",&N,&M);
    for(int i = 0; i<N;i++)
    {
        scanf("%d %d %d %d", &student[i].id, &student[i].score[1], &student[i].score[2], &student[i].score[3]);
        student[i].score[0] = student[i].score[1] + student[i].score[2]+ student[i].score[3];
    }
    // 计算等级
    for(now = 0; now< 4;now++){
        sort(student, student+N, cmp); // 0 1 2 3 表示按照 ACME
        Rank[student[0].id][now] = 1;
        for(int i = 1; i<N;i++)
        {
            if(student[i].score[now] == student[i-1].score[now]){
                Rank[student[i].id][now] = Rank[student[i-1].id][now];
            }else{
                Rank[student[i].id][now] = i+1;
            }

        }

    }
    // 处理查询
    char Map[4] = {'A','C','M','E'};
    int query;
    for(int i = 0; i<M;i++)
    {
        scanf("%d",&query);
        if(Rank[query][0] == 0)// 考生不存在
        {
            printf("N/A\n");
        }else{
            int m = 0;
            for(int j = 1; j<4;j++)
            {
                if(Rank[query][j]<Rank[query][m]){
                    m = j;
                }

            }
            printf("%d %c\n",Rank[query][m],Map[m]);

        }

    }
    return 0;
}
bool cmp(Student a, Student b){
    return a.score[now]>b.score[now];
}
