#include<stdio.h>
#include<string.h>
void rev(char strA[]);
int main()
{
    char strA[106],strB[106];

    scanf("%s %s",strA,strB);
    rev(strA);
    rev(strB);

    int len = strlen(strA) > strlen(strB)?strlen(strA):strlen(strB);
    char strC[106];
    for(int i = 0; i<len;i++)
    {
        int ai = i<strlen(strA)? (strA[i]-'0'):0;
        int bi = i<strlen(strB)?(strB[i]-'0'):0;
        if(i%2==0){ // 奇数为
            int result= (ai+bi)%13;
            if(result<10){
                strC[i] = result+'0';
            }else if(result==10){
                strC[i] = 'J';
            }else if(result == 11){
                strC[i] = 'Q';
            }else{
                strC[i] = 'K';
            }
        }else{
            int result = (bi-ai) < 0 ? (bi-ai+10):(bi-ai);
            strC[i] = result+'0';
        }
    }
    strC[len] = '\0';
    rev(strC);
    printf("%s\n",strC);

    return 0;


}
void rev(char strA[])
{
    int len = strlen(strA);
    char temp;
    for(int i = 0; i< len/2;i++)
    {
        temp = strA[i];
        strA[i] = strA[len-1-i];
        strA[len-1-i] = temp;
    }
}
