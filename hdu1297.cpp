#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 1e3 + 100;
typedef long long LL;
LL a[maxn][55];
int main(int argc, char const *argv[]){
	memset(a,0,sizeof(a));
	a[1][1] = 1;
	a[2][1] = 2;
	a[3][1] = 4;
	a[4][1] = 7;
	for (int i = 5; i < maxn; ++i){
		LL add = 0;
		for (int j = 1; j < 51; ++j){
			a[i][j] = a[i-1][j] + a[i-2][j] + a[i - 4][j] + add;
			add = a[i][j] / 10000000000;
			a[i][j] = a[i][j] % 10000000000;
			if(!add && a[i][j]==0)
				break;
		}
	}
	int n;
	while(scanf("%d",&n) != EOF){
		int k = 50;
		while(!a[n][k]) k--;
		printf("%lld",a[n][k--]);
		for (int i = k; i >=1 ; --i){
			printf("%010lld",a[n][k]);
		}
		printf("\n");
	}
	return 0;
}