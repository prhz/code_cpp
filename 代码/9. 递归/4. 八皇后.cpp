#include<stdio.h>
#include<math.h>
const int MAX=10;
const int n = 8;
int P[MAX];
int cunP[100][MAX];
bool hashTable[MAX] = {false};
int count=0;
void generateP(int index);
int main()
{
    generateP(1);

    int m;
    scanf("%d", &m);
    for(int i =0; i< m;i++)
    {
        int temp;
        scanf("%d",&temp);
        for(int j = 1; j<=8;j++)
        {
            printf("%d",cunP[temp-1][j]);
        }
        printf("\n");
    }
    return 0;
}

void generateP(int index)
{
    if(index == n+1){ // 生成合法序列
        // 记录
        for(int i = 1; i<=8;i++)
        {
            cunP[count][i] = P[i];
            //printf("%d",P[i]);
        }
        //printf("\n");
        count++;
        return;
    }
    for(int x = 1; x<=n;x++)
    {
        if(hashTable[x] == false){
            bool flag = true;
            for(int pre = 1; pre<index;pre++)
            {
                if(abs(index-pre) == abs(x-P[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if(flag){
                P[index] = x;
                hashTable[x] = true;
                generateP(index+1);
                hashTable[x] = false;
            }

        }

    }


}

