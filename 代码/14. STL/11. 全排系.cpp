#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{

    char str[10];
    while(scanf("%s", str)!=EOF){

        do{
            printf("%s\n", str);

        }while(next_permutation(str, str+strlen(str)));
        printf("\n");
    }

    return 0;
}
