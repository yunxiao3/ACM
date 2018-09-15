#include <stdio.h>
 
__int64 dp[36] = {0, 2};
 
int main(){
    int n;
    for(n = 2; n < 36; ++n) dp[n] = dp[n-1] * 3 + 2;
    while(scanf("%d", &n) == 1) printf("%I64d\n", dp[n]);
    return 0;
}

