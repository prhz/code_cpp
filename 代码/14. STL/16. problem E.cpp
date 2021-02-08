#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
stack<char> s;
bool judge(string str){
	for(int i=0;i<str.length() ;i++){
		if(str[i]=='('||str[i]=='['||str[i]=='{')	s.push(str[i]) ;
		if(str[i]==')'||str[i]==']'||str[i]=='}'){
			if(str[i]==')'){
				if(!s.empty() && s.top()=='('){
					s.pop() ;
				}
				else return false;
			}
			else if(str[i]==']'){
				if(!s.empty() &&s.top()=='['){
					s.pop() ;
				}
				else return false;
			}
			else if(str[i]=='}'){
				if(!s.empty() &&s.top()=='{'){
					s.pop() ;
				}
				else return false;
			}
		}
	}
	if(s.empty())	return true;
	return false;
}
int main(){
	int m;
	scanf("%d",&m);
	getchar();
	while(m--){
		string str;
		getline(cin,str);
		while(!s.empty() )	s.pop() ;
		if(judge(str)==true)	printf("yes\n");
		else printf("no\n");
	}
	return 0;
}


// 

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
bool isPiPei(char a, char b);
char str[100000];
int main()
{
	

	int n; 
	scanf("%d", &n);
	getchar();
	for(int i = 0; i< n;i++)
	{
		stack<char> st;
		gets(str);
		bool flag = true;
		for(int j = 0; j< strlen(str); j++)
		{
			if(str[j] == '[' || str[j] == '(' || str[j] =='{' )
			{
				st.push(str[j]);
				// printf("push: %c\n", str[j]);
			}
			if(str[j] == ']' || str[j] == ')' || str[j] =='}'){
				if(st.empty())
				{
					flag = false;
				}
				if(!st.empty() && isPiPei(st.top(), str[j])){
					// printf("pop: %c\n", st.top());
					st.pop();
				}
				
			}
		}
		if(!flag)
		{
			printf("no\n");
		}else{
		if(st.empty())
		{
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	}
	

	return 0;

}

bool isPiPei(char a, char b)
{
	if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
	{
		return true;
	}else{

		return false;
	}

}