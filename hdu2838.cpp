#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long maxn = 100100;

struct node{
	long long num ;
	long long sum ;
}c[maxn];

long long n;

long long lowbit(long long x){
	return x & (-x);
}

void upadte(long long i,long long x){
	while(i <= n){
		c[i].sum += x;
		c[i].num += 1;
		i += lowbit(i);
	}
}

long long getsum(long long i){
	long long sum = 0;
	while(i > 0){
		sum += c[i].sum;
		i -= lowbit(i);
	}
	return sum;
}

long long getnum(long long i){
	long long num = 0;
	while(i > 0){
		num += c[i].num;
		//cout << "i " << i <<" " <<num << " "; 
		i -= lowbit(i);

	}
	return num;
}


int main(int argc, char const *argv[]){
	while(cin >> n){
		memset(c,0,sizeof(c));
		long long a = 0;
		long long sum = 0;
		for (long long i = 1; i <= n; ++i){
			scanf("%lld",&a);
			upadte(a,a);
			sum += ((i - getnum(a)) * a + getsum(n) - getsum(a)); 
			//cout << a <<" " << getnum(a)<< " " << getsum(a) <<" " << sum << endl;
		}
		printf("%lld\n", sum);
	}
	return 0;
}