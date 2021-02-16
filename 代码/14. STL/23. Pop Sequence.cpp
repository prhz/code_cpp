#include<stdio.h>
#include<stack>

using namespace std;
bool Judge(int Array[], int m,int n);
int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int Array[1005];
    for(int i = 0; i < k;i++)
    {
        for(int j = 0; j< n;j++){
            scanf("%d",&Array[j]);
        }
        bool ans = Judge(Array,m, n);
        if(ans){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }


    return 0;
}
bool Judge(int Array[], int m,int n)
{
    stack<int> st;
    int index = 0;
    for(int i = 1; i<= n; i++)
    {
        st.push(i); // 入栈
        if(st.size()>m)
        {
            return false;
        }

        while(!st.empty() &&(st.top() == Array[index])){
            st.pop();
            index++;
        }

    }

    if(st.empty())
    {
        return true;
    }else{
        return false;
    }

}
