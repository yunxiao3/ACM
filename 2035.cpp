#include <iostream>
#include<cstdio>
typedef long long LL;
using namespace std;

int mul(LL a, LL b, int mod){
	LL ans = 1;
	while(b > 0){
		if(b & 1)
			ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}


int main(int argc, char const *argv[]){

	int a,b;
	while(cin >> a >> b){

		if(a == b && a == 0)
			break;
		cout << mul(a,b,1000)<<endl;

	}
	
	return 0;
}