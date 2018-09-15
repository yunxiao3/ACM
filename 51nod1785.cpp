#include <iostream>
using namespace std;
typedef long long LL;

LL k(LL n){
	LL res = 1;
	for (int i = 1; i <= n ; ++i){
		res *= i;
	}
	return res;
}

int main(int argc, char const *argv[]){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --){
		LL n;
		cin >> n;
		LL res = 0;
		for (LL i = 1; i < n ; ++i){
			res += i*k(i);
		}
		cout << res << " " << res % n << endl;
	}
	
	return 0;
}