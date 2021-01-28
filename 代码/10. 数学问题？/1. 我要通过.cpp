#include<stdio.h>
#include<string.h>

int main()
{
    char str[105];
    int N;
    scanf("%d", &N);
    for(int i = 0; i< N;i++)
    {
        scanf("%s",str);
        int len = strlen(str);

        int P_count = 0;
        int P_index = -1;
        int T_count = 0;
        int T_index = -1;
        int other = 0;

        for(int j = 0; j <len;j++)
        {
            if(str[j] == 'P')  {
                P_count ++;
                P_index = j;
            }else if(str[j] == 'T'){
                T_count++;
                T_index = j;
            }else if(str[j]!='A'){
                other++;
            }
        }
        if(P_count!=1||T_count!=1||other!=0||(T_index-P_index<=1)){
            printf("NO\n");
            continue;
        }
        int x = P_index;
        int y = T_index - P_index-1;
        int z = len-T_index-1;

        if(x==z-(y-1)*x)
        {
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }

    return 0;
}
