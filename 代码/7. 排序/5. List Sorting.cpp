#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct{
    char id[10];
    char name[10];
    int grade;
}Student;
Student student[100005];
bool cmp(Student a, Student b);
int C;
int main()
{
    int N;
    scanf("%d %d", &N,&C);
    for(int i = 0; i<N;i++)
    {
        scanf("%s %s %d", student[i].id, student[i].name, &student[i].grade);
    }
    sort(student,student+N,cmp);
    for(int i =0 ;i<N;i++)
    {
        printf("%s %s %d\n", student[i].id, student[i].name,student[i].grade);

    }

    return 0;
}
bool cmp(Student a, Student b)
{
    if(C==1){
        return strcmp(a.id,b.id) < 0;
    }else if(C==2){
        if(strcmp(a.name,b.name)!=0){
            return strcmp(a.name,b.name)< 0;
        }else{
             return strcmp(a.id,b.id) < 0;
        }
    }else if(C==3){
        if(a.grade != b.grade){
            return a.grade < b.grade;
        }else{
            return strcmp(a.id,b.id) < 0;
        }
    }else{
        return false;
    }

}
