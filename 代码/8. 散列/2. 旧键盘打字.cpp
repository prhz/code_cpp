#include<stdio.h>
#include<string.h>
int main()
{
    bool HashTable[128];// 表能用
    memset(HashTable, true, sizeof(HashTable));
    char huai[100];
    char str[100005];
    gets(huai);
    gets(str);
    int len1 = strlen(huai);
    int len2 = strlen(str);
    for(int i = 0;i<len1;i++)
    {
        char c = huai[i];
        if(c>=0 && c<=9)
        {
            HashTable[c] = false;
        }else if(c>='A' && c<='Z'){
            HashTable[c] = false;
            HashTable[c+32] = false;
        }else if(c == '+'){
            for(int j = 'A'; j<='Z';j++)
            {
                HashTable[j] = false;
            }
        }else{
            HashTable[c] = false;
        }
    }

    for(int i = 0; i < len2;i++)
    {

        if(HashTable[str[i]]){
            printf("%c",str[i]);
        }

    }
    return 0;

}
