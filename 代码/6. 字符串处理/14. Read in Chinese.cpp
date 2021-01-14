#include<stdio.h>
#include<string.h>

int main()
{
    char num[10][5] = {"ling","yi","er", "san","si","wu","liu","qi","ba","jiu"};
    char wei[5][5] = {"Shi","Bai","Qian","Wan","Yi"};

    char str[20];
    scanf("%s", str);
    int len = strlen(str);

    int left = 0;
    int right = len-1;

    if(str[0] == '-'){
        printf("Fu");
        left++;
    }
    while(left+4<=right)
    {
        right -= 4;
    }

    while(left<len) // 每次处理一节
    {
        bool flag = false; // 表示是否有累积的0
        bool isPrint = false; // 表示该节中是否输出过

        while(left<=right) // 处理该节中的每一位
        {
            if(left>0&&str[left]=='0')
            {
                flag = true;
            }else{ // 当前为 ！=0
                if(flag == true){ // 存在累积的 0

                    printf(" ling");
                    flag = false;
                }
                // 只要不是首位，前输出空格
                if(left >0)
                {
                    printf(" ");
                }
                printf("%s", num[str[left] - '0']);
                isPrint = true;
                if(left != right){ // 本节中处了个位， 输出shibaiqian
                    printf(" %s", wei[right-left-1]);
                }


            }
            left++;

        }
        if(isPrint == true && right !=len-1) // 只要不是个位节，就输出wanYI
        {
            printf(" %s", wei[(len-1-right)/4+2]);
        }
        right+=4;





    }


    return 0;
}
