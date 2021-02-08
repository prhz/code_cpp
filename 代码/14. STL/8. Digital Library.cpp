#include<stdio.h>
#include<set>
#include<string>
#include<map>
#include<iostream>

using namespace std;
void query(map<string, set<int> > &mp, string &target);
int main()
{
    map<string, set<int> > Title, Author, KeyWord, Publisher, Years;

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N;i++)
    {
        int id;
        string title, author, keyword, publisher, year;
        scanf("%d", &id);
        getchar();
        getline(cin, title);
         Title[title].insert(id);
        getline(cin, author);
        Author[author].insert(id);
       while(cin >> keyword)
       {
           KeyWord[keyword].insert(id);
           char c = getchar();
           if(c == '\n')    break;
       }

        getline(cin, publisher);
         Publisher[publisher].insert(id);
        getline(cin, year);
          Years[year].insert(id);

    }
    int M;
    scanf("%d", &M);
    for(int i = 0; i< M;i++)
    {
        int type;
        string temp;

        scanf("%d: ", &type);
        getline(cin, temp);
        cout << type << ": " << temp<<endl;
        if(type == 1) query(Title, temp);
        else if(type == 2) query(Author, temp);
        else if(type == 3) query(KeyWord, temp);
        else if(type == 4) query(Publisher, temp);
        else query(Years, temp);


    }


    return 0;
}
void query(map<string, set<int> > &mp, string &target)
{
    if(mp.find(target)!=mp.end())
    {
       for(set<int>::iterator it = mp[target].begin(); it!=mp[target].end(); it++){
            printf("%07d\n", *it);
       }
    }else{
        printf("Not Found\n");
    }


}
