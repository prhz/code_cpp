#include <stdio.h>
#include <string.h>

int main()
{
    char str[85];
    scanf("%s", str);

    int len = strlen(str);
    int n1 = (int)((len+2)/3.0);
    int n3 = n1;
    int n2 = len + 2 - n1 - n3;
    for(int i = 0; i< n1; i++)
    {
        if(i < n1-1) // 前 n1 -1 行
        {
            printf("%c",str[i]);
            for(int j = 1; j<n2-1;j++)
            {
                printf(" ");
            }
            printf("%c\n", str[len-i-1]);

        }else{ // 第 n1 行
            for(int j = 0; j<n2;j++)
            {
                printf("%c", str[i+j]);
            }
            printf("\n");
        }
    }

    return 0;
}
