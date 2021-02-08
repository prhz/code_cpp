#include<cstdio>
#include<algorithm>
using namespace std;
int a[10];
void input()
{
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
}
void deal()
{
	int min=0;
	for(int i=0;i<10;i++){
		if(a[i]<a[min]) min=i;
	}
	swap(a[0],a[min]);
	int max=0;
	for(int i=0;i<10;i++){
		if(a[i]>a[max]) max=i;
	}
	swap(a[9],a[max]);
}
void output()
{
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}
int main()
{
	input();
	deal();
	output();
	return 0;
}