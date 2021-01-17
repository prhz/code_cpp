#include<stdio.h>
#include<algorithm>

using namespace std;
typedef struct{
    int left;
    int right;
}QuJian;
bool cmp(QuJian q1, QuJian q2);
int main()
{
    int n;
    QuJian qujian[105];
    while(scanf("%d",&n)!=-1){
        if(n==0){break;}
        for(int i =0; i< n;i++)
        {
            scanf("%d %d",&qujian[i].left, &qujian[i].right);
        }

        sort(qujian ,qujian+n,cmp);
        int result = 1;
        int nowLeft = qujian[0].left;
        for(int i = 1; i< n;i++)
        {
            if(qujian[i].right <= nowLeft)
            {
                nowLeft = qujian[i].left;
                result++;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}

bool cmp(QuJian q1, QuJian q2)
{
    if(q1.left != q2.left)  return q1.left>q2.left;
    else{
        return q1.right<q2.right;

    }
}
