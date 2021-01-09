#include <stdio.h>
#include <string.h>
typedef struct
{
    char id[20];
    int seat;
}Info;

int main()
{
    Info stu[1005];
    int N;
    scanf("%d", &N);

    char temp_id[20];
    int index;
    int temp_seat;
    for(int i = 0; i<N;i++)
    {

        scanf("%s %d %d", temp_id, &index, &temp_seat);
        strcpy(stu[index].id, temp_id);
        stu[index].seat = temp_seat;
    }
    int M;
    scanf("%d", &M);
    for(int i = 0; i<M; i++)
    {
        int target;
        scanf("%d", &target);
        printf("%s %d\n",stu[target].id, stu[target].seat);
    }

    return 0;
}
