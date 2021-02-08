#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string sentance;
    map<string, int > mp;
    getline(cin, sentance);
    int pos = 0;

    // Can1: "Can a can can a can?  It can!"
    while(pos < sentance.length())
    {
        string word;
        while(pos<sentance.length() && isalnum(sentance[pos]))
        {
            if(sentance[pos]>='A' && sentance[pos]<='Z'){
                sentance[pos] = sentance[pos] + 'a' - 'A';
            }
            word+=sentance[pos];

            pos++;
        }
        if(word!=""){
            if(mp.find(word)!=mp.end())
            {
                mp[word]++;
            }else{
                mp[word] = 1;
            }

        }
        while(pos<sentance.length() && !isalnum(sentance[pos]))
        {
            pos++;
        }


    }

    map<string ,int>:: iterator it, ma;
    ma = mp.begin();
    for(it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second > ma->second)
        {
            ma = it;
        }

    }
    cout << ma->first << " "<< ma->second<<endl;
    return 0;
}
