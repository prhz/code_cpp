#include <stdio.h>

int main()
{
        int P[1005] = {0};

        int x,e;
        while(scanf("%d %d", &x, &e)!=EOF)
        {
            P[e] = x;
        } // 保存多项式

        P[0] = 0; // 0此项导数为0
        int count = 0;
        for(int i = 1; i <= 1000; i++)
        {
            P[i-1] = P[i] * i;
            P[i] = 0;
            if(P[i-1]!=0){
                count ++;
            }
        }
        if(count == 0){

            printf("0 0"); // 特判
        }else{
            for(int i = 1000; i>=0; i--)
            {
                if(P[i] != 0){
                    printf("%d %d", P[i], i);
                    count --;
                   
                }
                 if(count != 0){
                        printf(" ");
                    }
                

            }

        }

        return 0;

}