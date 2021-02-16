#include<stdio.h>
#include<math.h>
int Array[1005];
int main()
{
    int n, d;
    while(scanf("%d", &n)!=EOF){
        if(n == 0){
            break;
        }
        for(int i = 1; i<= n;i++)
        {
            scanf("%d", &Array[i]);
        }
        scanf("%d", &d);

        int low = pow(2, d-1);
        low = low > n ? n+1 : low;
        int high = pow(2, d);
        high = high > n ? n+1 : high;
        int count = 0;
        for(int i = low ; i< high;i++)
        {
            printf("%d", Array[i]);
            count ++;
            if(i<high-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
        if(count == 0)
        {
            printf("EMPTY\n");
        }
    }   
    return 0;
}