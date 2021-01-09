#include <stdio.h>
#include <string.h>

typedef struct {
    char name[15];
    char id[15];
    int score;
}Stu;
int main()
{
    Stu stuInfo[105];
    int n;
    scanf("%d", &n);
    char temp_name[15];
    char temp_id[15];
    int temp_score;
    for(int i =0; i<n;i++)
    {
        scanf("%s %s %d", temp_name, temp_id, &temp_score);
        strcpy(stuInfo[i].name, temp_name);
        strcpy(stuInfo[i].id, temp_id);
        stuInfo[i].score = temp_score;
    }
    int Max_score=-1,Min_score=105;
    int Max_index=-1,Min_index=-1;
    for(int i = 0; i< n;i++)
    {
        if(Max_score < stuInfo[i].score)
        {
            Max_score = stuInfo[i].score;
            Max_index = i;
        }
        if(Min_score > stuInfo[i].score)
        {
            Min_score = stuInfo[i].score;
            Min_index = i;
        }
    }
    printf("%s %s\n", stuInfo[Max_index].name, stuInfo[Max_index].id);
     printf("%s %s\n", stuInfo[Min_index].name, stuInfo[Min_index].id);

    return 0;
}
