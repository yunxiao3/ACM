#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5000+10;
char s[maxn];
int dp[maxn];
int main(){
	scanf("%s",s+1);
	int len = strlen(s+1);
	dp[0] = 0;
	for (int i = 1; i <= len ; ++i)
		dp[i] = i;

	for (int i = 1; i <= len; ++i){
		for (int j = i,k = i; j > 0 && k <= len; ++k,--j)
			if(s[j] == s[k]){
				dp[k] = min(dp[k],dp[j - 1] + 1);
				// cout<<"dp1 " << dp[k] << endl;
			}
			else
				break;
		for (int j = i,k = i + 1; j > 0 && k <= len; ++k,--j)
			if(s[j] == s[k]){
				dp[k] = min(dp[k],dp[j - 1] + 1);
				// cout<<"dp2 " << dp[k] << endl;

			}
			else
				break;
	}		
		printf("%d\n",dp[len] );



	return 0;
}
