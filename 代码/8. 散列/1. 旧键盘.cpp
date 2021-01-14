#include<stdio.h>
#include<string.h>

int main()
{
    char str1[100];
    char str2[100];
    bool HashTable[128] = {false};
    gets(str1);
    gets(str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i = 0; i< len1 ;i++)
    {

        int j;
        char c1, c2;
        for(j = 0; j< len2 ; j++)
        {
            c1 = str1[i];
            c2 = str2[j];
            if(c1 >= 'a' && c1 <='z')   c1 = c1-32;
            if(c2 >= 'a' && c2 <='z')   c2 = c2-32;

            if(c1 == c2)    break;// 字符相同，则不输出，进行下一字符

        }
        if(j == len2 && !HashTable[c1])
        {
            printf("%c", c1);
            HashTable[c1] = true;
        }
    }


    return 0;
}
