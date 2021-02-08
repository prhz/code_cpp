#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int significant;
string predeal(string str, int& index);

int main()
{

    string str1, str2;

    cin >> significant>> str1>> str2;
    int index1 = 0;
    int index2 = 0;
    string str11 = predeal(str1, index1);
    string str22 = predeal(str2, index2);
    if(str11 == str22 && index1 == index2)
    {
        cout << "YES 0."<<str11<<"*10^"<<index1<<endl;

    }else{
        cout<< "NO 0." <<str11<<"*10^"<<index1<<" 0."<<str22<<"*10^"<<index2<<endl;
    }
    return 0;

}
string predeal(string str, int& index)
{
    int k = 0;
    // 去除签到的0
    while(str.length()>0 && str[0] == '0')
    {
        str.erase(str.begin());
    }
    if(str[0] == '.') // 是小数 .123 .0123
    {
        str.erase(str.begin()); // 去除小数点
        while(str.length()>0 && str[0] == '0')
        {
            str.erase(str.begin());
            index--;
        } // 123
    }else{
        while(k<str.length()&&str[k]!='.')
        {
            k++;
            index++;
        }
        if(k<str.length())
        {
        str.erase(str.begin()+k);
        }

    }

    if(str.length()==0)
    {
        index = 0;
    }

    int num = 0;
    k = 0;
    string res;
    while(num<significant)
    {
        if(k<str.length())
        {
            res+=str[k++];
        }else{
            res+='0';
        }
        num++;
    }
    return res;
}
