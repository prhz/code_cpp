#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;

int main()
{
    string HXW[13] = {"tret", "jan","feb","mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string JHXW[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    // [0 , 169) 对应 火星文 最多两个字段
    map<string , int> mp1;
    map<string , int> mp2;
    for(int i = 0; i<=12;i++)
    {
        mp1[HXW[i]]= i;
    }
    for(int i = 0; i<=11;i++)
    {
        mp2[JHXW[i]]= i+1;
    }
    int N;
    scanf("%d", &N);
    getchar();
    for(int i = 0; i< N;i++)
    {
        string temp;
        getline(cin, temp);
        if(isdigit(temp[0])) // 处理 数字 -》HXW
        {
            int value = atoi(temp.c_str());

            int shang = value / 13;
            int yu = value % 13;
            if(shang == 0)
            {
                cout << HXW[yu] << endl;
            }else if(yu == 0)
            {

                cout << JHXW[shang -1] <<endl;
            }
            else{
                cout << JHXW[shang-1] << " "<<HXW[yu]<<endl;
            }


        }else{ // 火星 》数字
            map<string, int >::iterator it;
           int pos = temp.find(" ");
            if(pos == string::npos)
            {

                it = mp1.find(temp);
                if(it != mp1.end())
                {
                    cout << it->second <<endl;
                }else{

                    it = mp2.find(temp);
                    cout << 13*it->second <<endl;
                }

            }else{
                map<string, int >::iterator it1, it2;

                 it1 = mp2.find(temp.substr(0,pos));

                 it2 = mp1.find(temp.substr(pos+1,3));
                cout << it1->second * 13 + it2->second << endl;

            }

        }


    }
    return 0;

}
