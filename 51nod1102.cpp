#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 50000;

int main(int argc, char const *argv[]){
	

	long long a[maxn];
	long long l[maxn], r[maxn];
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		scanf("%lld",a+i);

	for (int i = 1; i <= n; ++i){
		 int k = i - 1;
		 while(a[k] >= a[i] && k >= 1)
		 	k = l[k] - 1;
		 l[i] = k + 1;
	}


	for (int i = n; i >= 1; --i){
		int k = i + 1;
		while(a[k] >= a[i] && k <= n)
			k = r[k] + 1;
		r[i] = k - 1;
	}

	long long ans = 0;
	for (int i = 1; i <= n ; ++i)
		ans = max(ans,a[i] * (r[i] - l[i] + 1));
	printf("%lld\n",ans );
	return 0;
}