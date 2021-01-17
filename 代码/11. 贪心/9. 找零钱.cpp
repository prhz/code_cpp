#include<stdio.h>

int main()
{
    int n;

    int Mianzhi[5] = {50,20, 10, 5,1};
    while(scanf("%d",&n)!=EOF)
    {
        int result[5]={0,0,0,0,0};
        for(int i =0; i< 5;i++){
            while(n>=Mianzhi[i])
            {
                n = n-Mianzhi[i];
                result[i]++;
            }

        }
        int flag = true;
        for(int i = 0;i<5;i++)
        {
            if(flag){
                if(result[i]!=0)
                {
                    printf("%d*%d",Mianzhi[i],result[i]);
                    flag = false;
                }

            }else{
                if(result[i]!=0)
                {
                    printf("+%d*%d",Mianzhi[i],result[i]);
                }
            }

        }
        printf("\n");

    }


    return 0;
}
