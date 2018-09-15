#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 1e4;
int dp[maxn];
int main(int argc, char const *argv[]){
	int num[6];
	int casenum = 1;
	while(true){
		int sum = 0;
		for (int i = 0; i < 6; ++i){
			scanf("%d",num+i);
			sum += (i+1)*num[i];
		}
		if(!sum)
			break;
		if(sum&1){
			printf("Collection #%d\n", casenum);
			printf("Can't be divided.\n");
		}
		else{
			memset(dp,0,sizeof(dp));
			int half = sum >> 1;
			for (int i = 1; i <= 6; ++i){
				if(num[i]){
					int k = min(num[i],half / i);
					for(int j = i; j <= k; j++)
						dp[j] = max(dp[j-1],dp[j-i]+i);
				}
			}
			if(dp[half] == half){
				printf("Collection #%d\n", casenum);
				printf("Can be divided.\n");
				printf("half: %d\n", dp[half]); 
			}
			else{
				printf("Collection #%d\n", casenum);
				printf("Can't be divided.\n");
			}
		}
		casenum++;		
	}
	return 0;
}