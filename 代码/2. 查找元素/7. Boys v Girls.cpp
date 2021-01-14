#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];
    char id[20];
    char gender;
    int score;
}Student;
int main()
{
    int N;
    Student temp;
    Student MaxF;
    MaxF.score = -1;
    Student MinM;
    MinM.score = 101;
    int countF = 0;
    int countM = 0;

    scanf("%d", &N);
    for(int i = 0; i<N;i++)
    {
        scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.score);
        if(temp.gender=='F'){//女
            countF ++;
            if(temp.score>MaxF.score){
                MaxF = temp;

            }
        }
        if(temp.gender=='M'){
            countM++;
            if(temp.score < MinM.score){
                MinM = temp;
            }
        }

    }
    if(countF!=0){
        printf("%s %s\n",MaxF.name, MaxF.id);
    }else{
        printf("Absent\n");
    }
    if(countM!=0){
        printf("%s %s\n", MinM.name, MinM.id);
    }else{
        printf("Absent\n");
    }
    if(countF == 0 || countM == 0){
        printf("NA\n");
    }else{
        printf("%d\n", MaxF.score - MinM.score);
    }
    return 0;
}
