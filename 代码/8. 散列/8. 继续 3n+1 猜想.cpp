#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
    bool hashtable[10005];
    int value[105];
    memset(hashtable,true,sizeof(hashtable));
    int K;
    scanf("%d",&K);
    int v;
    for(int i =0; i< K;i++)
    {
        scanf("%d", &v);
        value[i] = v;
        if(hashtable[v]){
            // 3n+1猜想处理
            while(v!=1){
                if(v%2==0){
                    v = v/2;
                    hashtable[v] = false;
                }else{
                    v = (3*v+1)/2;
                    hashtable[v] = false;

                }
            }

        }
    }
    sort(value, value+K);

    bool first = true;
    for(int i = K-1;i>=0;i--){
        if(hashtable[value[i]]){
            if(first){
                printf("%d",value[i]);
                first = false;
            }else{
                printf(" %d",value[i]);
            }
        }
    }
    return 0;
}
