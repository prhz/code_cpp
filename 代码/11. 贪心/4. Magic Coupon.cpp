#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    int NArray[100005];
    for(int i = 0; i<N;i++)
    {
        scanf("%d",&NArray[i]);
    }
    sort(NArray,NArray+N);
    int M;
    scanf("%d",&M);
    int MArray[100005];
    for(int i = 0; i< M;i++)
    {
        scanf("%d",&MArray[i]);
    }
    sort(MArray, MArray+M);

    int i = 0;
    int j = 0;
    int result = 0;
    while(i<N && j <M && NArray[i]<0 && MArray[j]<0)
    {
        result+=NArray[i] * MArray[j];
        i++;
        j++;
    }
    i = N-1;
    j = M-1;
    while(i>=0&&j>=0&&NArray[i]>0&&MArray[j]>0)
    {
        result+=NArray[i]*MArray[j];
        i--;
        j--;
    }
    printf("%d",result);


    return 0;
}
