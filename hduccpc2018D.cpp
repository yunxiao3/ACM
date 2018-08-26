#include <iostream>
#include <stdio.h>
using namespace std;


void print(long long x){
	if(x % 2 == 1)
		printf("%lld %lld\n",(x*x - 1) / 2 , (x*x + 1) / 2 );
	else{
		long long temp = x*x;
		temp /= 2;
		if(temp % 2 == 1)
			 printf("-1 -1\n");
		else
			printf("%lld %lld\n", (x*x/2 - 2)/2 , (x*x/2 + 2) / 2 );
	}
}

int main(int  argc, char const *argv[]){
	long long a, b, c, n;
	long long t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&a);
		if(n > 2 || n == 0)
			printf("-1 -1\n");
		if(n == 1)
			printf("1 %lld\n",a + 1);
		if(n == 2)
			print(a);
	}
	
	return 0;
}