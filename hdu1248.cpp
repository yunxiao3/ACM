#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
const int maxn = 1e5+100;
int dp[maxn];
int main(int argc, char const *argv[]){
	int t;
	scanf("%d",&t);
	int v[3] = {150,200,350};
	while(t--){
		int n;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < 3; i ++){
			for (int j = v[i]; j <= n; ++j)
					dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
		}
		printf("%d\n",n - dp[n]);
	}	
	return 0;
}
