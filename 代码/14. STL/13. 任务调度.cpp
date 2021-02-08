#include<stdio.h>
#include<queue>

#include<string>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
typedef struct Task{
    string name;
    int priority;
    friend bool operator < (Task t1, Task t2)
    {
        if(t1.priority != t2.priority)
        {
            return t1.priority < t2.priority; // 数字小，优先级高
        }else{
            return t1.name > t2.name;
        }
    }
}Task;
priority_queue<Task> tqueue;
map<string, int> mp;
void deal(string str);
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        deal(str);

    }
    // 遍历输出tqueue;

        while(tqueue.empty()!=1)
        {
            cout<<tqueue.top().name;
            if(tqueue.size()>1)
                cout<<" ";
            else
                cout<<endl;
            tqueue.pop();
        }

    return 0;
}

void deal(string str)
{

    int pos = 0;
    string task="";

    while(pos < str.length() && str[pos]!='(')
    {
        task+=str[pos];
        pos++;
    }
    if(mp[task] == 0)
    {
        Task t;
        t.name = task;
        t.priority = 0;
        mp[task] = 0;
        tqueue.push(t);
    }
    pos++;
    int temp = mp[task]+1;
    task = "";
    while(pos < str.length())
    {
        if(str[pos] != ',' && str[pos]!=')')
        {
            task+=str[pos];
        }else{
            if(task != "NULL" && mp[task] != 0)
            {
                Task t;
                t.name = task;
                t.priority = temp;
                mp[task] = temp;
                tqueue.push(t);
                task = "";
            }
        }
        pos++;
    }
}
