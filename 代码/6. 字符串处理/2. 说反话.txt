#include <stdio.h>
#include <string.h>
int main()

{
    char strs[85][30];
    char temp[30];
    int index = 0;
    while(scanf("%s", temp)!=EOF){
        strcpy(strs[index++], temp);
    }
    for(int i = index-1;i>=0;i--)
        {
            printf("%s",strs[i]);
            if(i > 0){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    return 0;
}
