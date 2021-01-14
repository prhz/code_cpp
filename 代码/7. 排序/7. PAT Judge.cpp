#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct{
    int id;
    int score[6];
    int sum_score;
    int pcount;
    bool doprint;
}Student;
Student student[100000];
bool cmp(Student a, Student b);
int main()
{
    int N,K,M;
    int p[6];
    scanf("%d %d %d", &N,&K,&M);
    for(int i = 1; i<=N;i++)
    {
        student[i].doprint = false;
        student[i].id = i;
        student[i].pcount = 0;
        memset(student[i].score, -1, sizeof(student[i].score));
        student[i].sum_score = 0;
    }
    for(int i = 1; i<=K;i++)
    {
        scanf("%d",&p[i]);
    }
    int temp_tid,temp_score,temp_id;
    for(int i =0; i<M;i++)
    {
        scanf("%d %d %d",&temp_id ,&temp_tid, &temp_score);


        if(temp_score != -1){ //提交通过编译
            student[temp_id].doprint = true;
        }
        if(temp_score == -1 && student[temp_id].score[temp_tid] == -1){ // 第一次未通过编译，修改成绩为0
            temp_score = 0;
        }

        if(temp_score == p[temp_tid] && student[temp_id].score[temp_tid]<p[temp_tid]){ // 第一次得满分
            student[temp_id].pcount++;
        }
        if(temp_score>student[temp_id].score[temp_tid]){ //修改score
            student[temp_id].score[temp_tid] = temp_score;
        }
    }
    // 计算总分
    for(int i = 1; i<= N;i++)
    {
        for(int j = 1; j<=K;j++)
        {
            if(student[i].score[j]!=-1){
                student[i].sum_score+=student[i].score[j];
            }
        }
    }
    sort(student+1, student+N+1, cmp);
    int r = 1;
    for(int i = 1; i<=N && student[i].doprint; i++)
    {
        if(i>1 && student[i].sum_score != student[i-1].sum_score){
            r = i;
        }
        printf("%d %05d %d",r,student[i].id,student[i].sum_score);
        for(int j = 1; j<=K;j++)
        {
            if(student[i].score[j]==-1){
                printf(" -");
            }else{
                printf(" %d", student[i].score[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
bool cmp(Student a, Student b)
{
    if(a.sum_score!=b.sum_score)    return a.sum_score > b.sum_score;
    else if(a.pcount != b.pcount)   return a.pcount > b.pcount;
    else return a.id < b.id;

}

