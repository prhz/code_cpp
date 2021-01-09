#include <stdio.h>
#include <string.h>
typedef struct {
    char id[25];
    int hh;
    int mm;
    int ss;
}Info;
bool IsMoreEqual(Info a, Info b);
bool IsLessEqual(Info a, Info b);
int main()
{
    Info temp;
    Info SignIn;
    SignIn.hh = 23;
    SignIn.mm = 59;
    SignIn.ss = 59;

    Info SignOut;
    SignOut.hh = 00;
    SignOut.mm = 00;
    SignOut.ss = 00;

    int N;
    scanf("%d", &N);
    for(int i = 0; i< N;i++)
    {
        scanf("%s %d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
        if(IsLessEqual(temp, SignIn))
        {
            SignIn = temp;
        }
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
        if(IsMoreEqual(temp, SignOut))
        {
            SignOut = temp;
        }
    }
    printf("%s %s\n", SignIn.id, SignOut.id);

}
bool IsMoreEqual(Info a, Info b)
{
    if(a.hh!=b.hh){
        return a.hh >= b.hh;
    }else if(a.mm!=b.mm){
        return a.mm >= b.mm;
    }else if(a.ss!=b.ss){
        return a.ss >= b.ss;
    }else{
        return false;
    }

}
bool IsLessEqual(Info a, Info b)
{
    if(a.hh!=b.hh){
        return a.hh <= b.hh;
    }else if(a.mm!=b.mm){
        return a.mm <= b.mm;
    }else if(a.ss!=b.ss){
        return a.ss <= b.ss;
    }else{
        return false;
    }

}
