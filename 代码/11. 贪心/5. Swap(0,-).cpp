#include<stdio.h>

#include<algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    int Array[100005];
    int left = N-1;
    int num;
    for(int i =0;i<N;i++)
    {
        scanf("%d", &num);
        Array[num] = i;
        if(num==i && num!=0)
        {
            left--;
        }
    }
    int k = 1;
    int result = 0;
    while(left>0)
    {
        if(Array[0]==0)
        {
            // 寻早不在位置的
            while(k<N){
                if(Array[k]!=k){
                    swap(Array[0],Array[k]);
                    result++;
                    break;
                }
                k++;
            }

        }
        while(Array[0]!=0){
            swap(Array[0],Array[Array[0]]);
            result++;
            left--;
        }
    }
    printf("%d",result);

    return 0;
}
