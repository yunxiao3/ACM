#include <iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
int mul(LL x, LL n){
	int ans = 1;
	while(n > 0){
		if(n & 1)
			ans = x * ans % 10;
		x = x * x % 10;
		n >>= 1;
	}
	return ans;
}


int main(int argc, char const *argv[]){

	LL a, b;
	while(scanf("%lld%lld",&a,&b) != EOF){
		printf("%d\n",mul(a,b));
	}

	
	return 0;
}