#include<stdio.h>


int main()
{
    int Array[205] = {0};
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i = 0; i< n; i++)
        {
            scanf("%d", &Array[i]);
        }
        int x;
        int index = -1;
        scanf("%d", &x);
        for(int i = 0; i<n; i++)
        {
            if(x == Array[i])
            {
                index = i;
                break;
            }
        }
        printf("%d\n", index);

    };


}
