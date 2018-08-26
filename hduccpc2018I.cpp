#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p(ll a){
	int rt = 1;
	for (int i = 1; i < a; ++i){
		rt *= i;
	}
	return rt;
}

int main()
{
    ll u, v, w, n;
    ll ans = 0;
    while(~scanf("%lld", &n)){
    	for (int i = 0; i < n - 1; ++i){
    		scanf("%lld%lld%lld",&u,&v,&w);
    		ans+=w;
    	}
    	printf("%lld\n",p(n)*ans*(n-1)*2);
    }
    return 0;
}
