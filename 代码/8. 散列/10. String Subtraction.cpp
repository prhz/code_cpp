#include<stdio.h>
#include<string.h>

int main()
{
    bool hashtable[128];
    memset(hashtable,true,sizeof(hashtable));
    char str1[10005],str2[10005];
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i =0; i<len2;i++)
    {
        hashtable[str2[i]] = false;
    }
    for(int i =0;i<len1;i++)
    {
        if(hashtable[str1[i]])
        {
            printf("%c",str1[i]);
        }
    }

    return 0;
}
