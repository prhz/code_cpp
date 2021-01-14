#include <stdio.h>

int main()
{
        int D, b;
        scanf("%d %d", &D,&b);

        int strb[40];
        int len=0;
        // 十进制转 b 进制
        do{
            strb[len++] = D%b;
            D = D/b;
        }while(D!=0);

        bool flag = true;
        for(int i = 0; i < len /2;i++)
        {
            if(strb[i]!=strb[len-1-i])
            {
                flag = false;
                break;
            }

        }
        if(flag)
        {
            printf("Yes\n");
        }else{
            printf("No\n");
        }
        for(int i = len-1; i>=0;i--)
        {
            printf("%d",strb[i]);
            if(i>0){
                printf(" ");
            }else{
                printf("\n");
            }

        }
}
