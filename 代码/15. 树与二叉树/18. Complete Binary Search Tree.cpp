#include <stdio.h>
#include<algorithm>
using namespace std;
void Inorder(int root);
int CBT[1005];
int Array[1005];
int n;
int num;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i< n;i++)
    {
        scanf("%d", &Array[i]);
    }
    sort(Array, Array+n);
    num = 0;
    Inorder(1);

    for(int i = 1 ; i<=n;i++)
    {
        printf("%d", CBT[i]);
        if(i<=n-1)
        {
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}

void Inorder(int root)
{
    if(root > n)
    {
        return;
    }
    Inorder(root*2);
    CBT[root] = Array[num++];
    Inorder(root*2+1);

}
