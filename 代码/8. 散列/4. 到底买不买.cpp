#include<stdio.h>
#include<string.h>

int main()
{
    int hashT[128];
    int hashM[128];
    memset(hashT,0,sizeof(hashT));
    memset(hashM,0,sizeof(hashM));
    char strT[1005];
    char strM[1005];
    gets(strT);
    gets(strM);
    int len1 = strlen(strT);
    int len2 = strlen(strM);
    for(int i =0; i<len1;i++)
    {
        hashT[strT[i]]++;
    }
    for(int i =0;i<len2;i++)
    {
        hashM[strM[i]]++;
    }
    bool flag = true;
    int que = 0;
    for(int i = 0; i< 128;i++)
    {
        if((hashT[i] - hashM[i])<0){
            flag = false;
            que += hashM[i] - hashT[i];
            
        }
    }
    if(flag){
        printf("Yes %d\n", len1 - len2);
    }else{
        printf("No %d\n", que);
    }
    return 0;
}
