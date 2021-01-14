#include <stdio.h>
#include<algorithm>

using namespace std;

typedef struct {
    int id;
    int de_score;
    int cai_score;
    int sumscore;
    int level; // 标注为第几类考生
}Student; // 只记录达标学生的信息
Student student[100005];
bool cmp(Student a, Student b);
int main()
{
    int N; // 考试总人数
    int L; // 录取最低分，德分和才分均不低于L才能被录取
    int H; // "才德全尽"，德分>=H, 才分>=H, level = 1, 按照德才总分排序
            // "德胜才", 得分>=H, L<=才分<德分，level = 2, 排在 level = 1之后，然后按照 总分进行排序
            // "才德兼亡-德胜才" L<=得分<H, L<=才分<H,得分>=才分 level = 3， 排在 level = 2之后，然后按照总分排序
            // 其他达到最低线的考生按照总分排序，L<=得分<H, L<=才分<H, 得分<才分 level = 4
    int M = 0; // 记录达到最低分数线的考生

    scanf("%d %d %d",&N,&L,&H);
    Student temp;

    for(int i = 0; i<N;i++)
    {
        scanf("%d %d %d", &temp.id,&temp.de_score, &temp.cai_score);
        if(temp.de_score >= H && temp.cai_score >= H){
            temp.sumscore = temp.de_score + temp.cai_score;
            temp.level = 1;
            student[M++] = temp;
        }else if(temp.de_score>=H && (temp.cai_score < H && temp.cai_score >= L)){
            temp.sumscore = temp.de_score + temp.cai_score;
            temp.level = 2;
            student[M++] = temp;
        }else if((temp.de_score>=L && temp.de_score<H) && (temp.cai_score>=L && temp.cai_score<H)&&(temp.de_score >= temp.cai_score)){
            temp.sumscore = temp.de_score + temp.cai_score;
            temp.level = 3;
            student[M++] = temp;
        }else if((temp.de_score>=L && temp.cai_score>=L)){
            temp.sumscore = temp.de_score + temp.cai_score;
            temp.level = 4;
            student[M++] = temp;
        } // else de < L && cai < L
    }
    sort(student, student+M, cmp);

    printf("%d\n", M);
    for(int i = 0; i<M;i++)
    {
        printf("%d %d %d\n", student[i].id, student[i].de_score, student[i].cai_score);
    }
    return 0;
}
bool cmp(Student a, Student b)
{
    if(a.level != b.level) return a.level < b.level;
    else if(a.sumscore != b.sumscore) return a.sumscore > b.sumscore;
    else if(a.de_score != b.de_score) return a.de_score > b.de_score;
    else return a.id < b.id;

}
