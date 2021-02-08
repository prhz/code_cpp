#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
int main()
{
    char str[205];
    while(gets(str)!=NULL)
    {
        reverse(str, str+strlen(str));
        printf("%s\n",str);
    }


    return 0;
}
