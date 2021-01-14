#include <stdio.h>

#include <string.h>


int main()
{
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int M[17] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int N;
    scanf("%d", &N);
     int flag1 = true;
    for(int i = 0; i< N;i++)
    {
        char temp[20];
        scanf("%s", temp);
        int flag = true;

        for(int j = 0; j< 17;j++)
        {
            if(temp[j]<'0' ||temp[j]>'9'){
                flag = false;
                printf("%s\n",temp);
                break;
            }
        }
        if(flag){
            int Z= 0;
            for(int j = 0; j< 17;j++)
            {
                Z+=(temp[j] - '0')*weight[j];
            }
            Z = Z%11;
            char m = M[Z];
            if(m != temp[17]){
                flag1 = false;
                printf("%s\n", temp);
            }

        }

    }
     if(flag1){
            printf("All passed\n");
        }


    return 0;
}

#include <stdio.h>

#include <string.h>


int main()
{
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int M[17] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int N;
    scanf("%d", &N);
     int flag1 = true;
    for(int i = 0; i< N;i++)
    {
        char temp[20];
        scanf("%s", temp);
        int flag = true;
        int Z= 0;
        for(int j = 0; j< 17;j++)
        {
            if(temp[j]<'0' ||temp[j]>'9'){
                flag = false;        
                break;
            }
            Z+=(temp[j] - '0')*weight[j];
        }
        Z = Z%11;
        char m = M[Z];
        if((flag == false) || (m != temp[17])){
                flag1 = false;
                printf("%s\n", temp);
            }

        }

   
    if(flag1){
        printf("All passed\n");
    }


    return 0;
}

