#include<stdio.h>
#include<string.h>

void rev(char str[]);
int main()
{
    char sentence[105][300] = { 0};

    int N;
    scanf("%d",&N);
    getchar();
    int len = 300;
    for(int i = 0; i<N;i++)
    {

        fgets(sentence[i], 300,stdin);
        sentence[i][strlen(sentence[i])-1] ='\0';
        rev(sentence[i]);
        int len = strlen(sentence[i]);
        if(len>strlen(sentence[i])){
            len = strlen(sentence[i]);
        }
    }
    char buf[300];
    for(int i = 0; i<len;i++)
    {
        int flag = true;
        char c = sentence[0][i];

        for(int j = 1; j<N;j++)
        {
            if(sentence[j][i]!=c){
                flag = false;
            }
        }
        if(flag){
            buf[i] = c;
        }else{
            buf[i] = '\0';
            break;
        }
    }
    rev(buf);

    if(strlen(buf)>0){
        printf("%s\n", buf);
    }else{
        printf("nai\n");
    }

    return 0;
}

void rev(char str[])
{
    int len = strlen(str);
    for(int i =0;i<len/2;i++)
    {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }

}
