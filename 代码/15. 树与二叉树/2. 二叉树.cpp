#include <stdio.h>
void func(int m);
int ans;
int n;
int main()
{
	int m;

	while(scanf("%d %d", &m, &n)!=EOF){
		ans = 0;
		if(m == 0 && n == 0){
			break;
		}
		int left = m;
		int right = m;
		while(left <= n){
			ans += right-left+1;

			left = left * 2;
			right = right * 2 +1;
			if(right > n){
				right = n;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}


