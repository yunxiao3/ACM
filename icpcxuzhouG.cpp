#include <iostream>
#include <stdio.h>
#include<set>
using namespace std;
typedef long long LL;
const int maxn = 50000+100;
LL a[maxn],b[maxn];
int n;
LL solve(LL *a){
	set<LL> s;
	LL ans = a[n-1];
	s.insert(a[n-1]);
	set<LL> :: iterator it;
	for (int i = n - 2; i >= 0 ; --i){
		it = s.lower_bound(a[i]);
		if(it == s.begin())
			ans += a[i];
		else{
			it--;
			ans +=  a[i] - *it;
		}
		s.insert(a[i]);
	}
	return ans;
}
int main(int argc, char const *argv[]){
	    scanf("%d",&n);
		for (int i = 0; i < n; ++i)
	    	scanf("%lld%lld",a+i,b+i);
	    printf("%lld\n",solve(a)+solve(b));
  return 0;
}