#include<stdio.h>
#include<string.h>

int main()
{
    int PATest[6];
    memset(PATest,0,sizeof(PATest));
    char str[10005];
    gets(str);

    int len = strlen(str);
    for(int i = 0; i< len;i++)
    {
        char c = str[i];
        if(c == 'P'){
            PATest[0]++;
        }else if(c == 'A'){
             PATest[1]++;
        }else if(c == 'T'){
             PATest[2]++;
        }else if(c == 'e'){
             PATest[3]++;
        }else if(c == 's'){
             PATest[4]++;
        }else if(c == 't'){
             PATest[5]++;
        }
    }

    // 输出
    char Map[6] = {'P','A','T','e','s','t'};
    int sum = PATest[0]+PATest[1]+PATest[2]+PATest[3]+PATest[4]+PATest[5];

    while(sum>0)
    {
        for(int i = 0; i< 6;i++){
            if(PATest[i]>0){
                printf("%c", Map[i]);
                PATest[i]--;
                sum--;
            }
        }

    }

    return 0;
}
