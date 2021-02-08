#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    string temp;
    map<string , int > mp;
    for(int i = 0; i< N; i++)
    {
        for(int j = 0; j< M; j++)
        {
            cin >> temp;
            if(mp.find(temp)!=mp.end())
            {
                mp[temp] ++;
            }else{
                mp[temp] = 1;
            }
        }
    }

    map<string, int>::iterator it, ma;
    ma = mp.begin();

    for(it = mp.begin(); it!=mp.end(); it++)
    {
        if(it->second > ma->second)
        {
            ma = it;
        }
    }

    cout << ma->first<<endl;
    return 0;
}
