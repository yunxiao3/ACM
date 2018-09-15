#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define bug prlong longf("*************\n");
using namespace std;
const long long maxn = 1e5;
long long a[maxn];
int main(int argc, char const *argv[]){
	long long t;
	scanf("%lld",&t);
	for (long long k = 1; k <= t; ++k){
		long long n;
		scanf("%lld",&n);
		a[0] = 0;
		for (long long i = 1; i <= n; ++i)
			scanf("%lld",&a[i]);
		long long length = a[n] - a[n - 1];
		long long time = 1;
		long long ti = 1;
		long long ct = 1;
		// bug;
		for (long long i = n - 1; i > 0; --i){
			// bug;
			ti = (a[i] - a[i-1]) * ct / length; 
			if((a[i] - a[i-1]) * ct % length) 
				ti++;
			time += ti;			
			ct = ti;
			length = a[i] - a[i-1];
		}
		printf("Case #%lld: %lld\n",k,time);
	}

	return 0;
}	