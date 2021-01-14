#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct{
    char id[15];
    int score;
    int location_number;
    int location_rank;
}Student;
Student student[30005];
bool cmp(Student a, Student b);
int main()
{
    int N; // 考场数目
    int K; // 记录每个考场的人数
    scanf("%d", &N);
    int m = 0;
    for(int i = 0; i < N;i++)
    {
        scanf("%d", &K);
        for(int j = 0; j<K;j++){
            scanf("%s %d",student[m].id, &student[m].score);
            student[m].location_number = i+1;
            m++;
        }
        sort(student+m-K,student+m, cmp);
        int r = 1;
        for(int j = m-K; j<m;j++)
        {
            if(j>m-K && student[j].score!=student[j-1].score){
                r = j+1-(m-K);
            }
            student[j].location_rank = r;
        }
    }

    sort(student, student+m,cmp);
    printf("%d\n", m);
    int r = 1;
    for(int i = 0; i<m;i++){
        if(i>0 && student[i].score!=student[i-1].score){
                r = i+1;
        }
        printf("%s %d %d %d\n", student[i].id, r, student[i].location_number,student[i].location_rank);
    }



    return 0;
}

bool cmp(Student a, Student b)
{
    if(a.score != b.score)  return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;

}
