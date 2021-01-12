#include<stdio.h>
#include<string.h>
typedef struct{
    char name[20];
    char passwd[20];
    bool isChanged;

}Info;

int main()
{
    int N;
    scanf("%d",&N);
    Info persons[1005];
    int Count = 0;
    for(int i = 0; i<N;i++)
    {
        scanf("%s %s", persons[i].name, persons[i].passwd);

        persons[i].isChanged = false;
    }

    for(int i = 0; i<N;i++)
    {
        int len = strlen(persons[i].passwd);
        for(int j = 0; j<len;j++)
        {
            if(persons[i].passwd[j] == '1'){
                persons[i].passwd[j] = '@';
                persons[i].isChanged = true;

            }else if(persons[i].passwd[j] == '0'){
                persons[i].passwd[j] = '%';
                persons[i].isChanged = true;

            }else if(persons[i].passwd[j] == 'l'){
                persons[i].passwd[j] = 'L';
                persons[i].isChanged = true;

            }else if(persons[i].passwd[j] == 'O'){
                persons[i].passwd[j] = 'o';
                persons[i].isChanged = true;
            }
        }
        if(persons[i].isChanged){
            Count++;
        }

    }
    if(Count==0)
    {
        if(N==1){
            printf("There is 1 account and no account is modified\n");
        }else{
            printf("There are %d accounts and no account is modified\n",N);
        }
    }else{
        printf("%d\n", Count);
        for(int i = 0; i< N;i++)
        {
            if(persons[i].isChanged){
                printf("%s %s\n",persons[i].name,persons[i].passwd);
            }

        }
    }

    return 0;
}
