#include<stdio.h>
#include<string.h>

int main()
{
    int hashtable[128];
    memset(hashtable, 0, sizeof(hashtable));
    char str[1005];
    gets(str);

    int len = strlen(str);
    for(int i =0; i<len;i++)
    {
        if(str[i]>='A'&&str[i]<='Z'){
            hashtable[str[i]+32]++;
        }

        if(str[i]>='a'&&str[i]<='z'){
            hashtable[str[i]]++;
        }
    }
    int Max_index = 0;
    for(int i = 1;i<128;i++)
    {
        if(hashtable[Max_index] < hashtable[i]){
            Max_index = i;
        }
    }
    printf("%c %d", Max_index, hashtable[Max_index]);


}
