#include<stdio.h>
#include <string.h>

int main()
{
    char str[10005];
    char dishu[10005];
    char exp[10005];
    int pos;

    scanf("%s",str);
    for(int i = 0; i< strlen(str);i++)
    {
        if(str[i]!='E')
        {
            dishu[i] = str[i];
        }else{
            pos = i;
            dishu[i] = '\0';
            break;
        }

    }
    int j = 0;
    for(int i = pos+1;i<strlen(str);i++)
    {
        exp[j++] = str[i];
    }
    exp[j] = '\0';

    int e = 0;
    for(int i =1;i<strlen(exp);i++)
    {
        e = e*10+exp[i]-'0';
    }

    if(dishu[0]=='-'){ // 处理符号，+不输出，-输出
        printf("-");
    }
    // if e==0;
    if(e==0) // 处理指数为 0
    {
        for(int i = 1;i<strlen(dishu);i++)
        {
            printf("%c",dishu[i]);
        }
        printf("\n");
        return 0;
    }


    if(exp[0] == '-') // 处理指数为负
    {
        printf("0.");
        for(int i = 0;i <e-1;i++)
        {
            printf("0");
        }
        for(int i = 1; i<strlen(dishu);i++)
        {
            if(dishu[i]>='0'&&dishu[i]<='9')
            {
                printf("%c",dishu[i]);
            }
        }
        printf("\n");
    }
    if(exp[0] == '+') // 处理指数为正
    {
        if(strlen(dishu)-3>e){
            for(int i = 1; i<3+e;i++)
            {
                if(dishu[i]>='0'&&dishu[i]<='9')
                {
                    printf("%c",dishu[i]);
                }
            }
            printf(".");
            for(int i = 3+e;i<strlen(dishu);i++)
            {
                printf("%c", dishu[i]);
            }
            printf("\n");

        }else{
             for(int i = 1; i<strlen(dishu);i++)
            {
                if(dishu[i]>='0'&&dishu[i]<='9')
                {
                    printf("%c",dishu[i]);
                }

            }
            int count = e-(strlen(dishu)-3);
                for(int i = 0; i<count;i++)
                {
                    printf("0");

                }
                printf("\n");

        }

    }


    return 0;
}
