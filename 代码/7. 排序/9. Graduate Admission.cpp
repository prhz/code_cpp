#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct{
    int id;
    int Ge;
    int Gi;
    int sum;
    int Rank;
    int choice[6];
}Student;
typedef struct{
    int id;
    int Ynumber;
    int Snumber;
    int last;
    int SZid[40005];
}School;
Student student[40005];
School school[105];
bool cmp(Student a, Student b);
bool cmpId(int a, int b);
int main()
{
    int N,M,K;

    // 处理输入
    scanf("%d %d %d", &N,&M,&K);
    for(int i = 0;i<M;i++)
    {
        school[i].id = i;
        school[i].Snumber = 0;
        school[i].last = -1;
        scanf("%d",&school[i].Ynumber);
    }
    for(int i=0; i<N;i++)
    {
        student[i].id = i;

        scanf("%d %d",&student[i].Ge,&student[i].Gi);
        student[i].sum = student[i].Ge+student[i].Gi;
        for(int j = 0; j<K;j++)
        {
            scanf("%d", &student[i].choice[j]);
        }
    }

    // 排序
    sort(student, student+N,cmp);
    // 处理排名
    for(int i = 0; i< N;i++)
    {
        if(i>0 && student[i].sum==student[i-1].sum && student[i].Ge==student[i-1].Ge)
        {
           student[i].Rank = student[i-1].Rank;
        }else{
            
            student[i].Rank = i;
        }

    }



    // 处理录取
    for(int i = 0; i<N;i++)
    {
        // 处理第i个考生
        for(int j = 0; j<K;j++){
            int cho = student[i].choice[j];
            int num = school[cho].Snumber;
            int last = school[cho].last;
            if(num<school[cho].Ynumber || (last !=-1 && student[i].Rank == student[last].Rank))
            {
                school[cho].SZid[num] = i;
                school[cho].last = i;
                school[cho].Snumber++;
                break;
            }

        }

    }


    // 处理输出
    for(int i = 0; i< M;i++)
    {
        if(school[i].Snumber > 0){
            sort(school[i].SZid,school[i].SZid+school[i].Snumber, cmpId);
            for(int j = 0; j<school[i].Snumber;j++)
            {
                printf("%d", student[school[i].SZid[j]].id);
                if(j < school[i].Snumber-1){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
bool cmp(Student a, Student b)
{
    if(a.sum!=b.sum) return a.sum>b.sum;
    else return a.Ge > b.Ge;

}
bool cmpId(int a, int b)
{
    return student[a].id < student[b].id;
}
