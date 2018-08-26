#include<iostream>
using namespace std;
 
int main() {
	int ti,n,m;
	long long f[21] = {0,0,1},t[21] = {1,1,2};
	for(int i=3;i<=20;i++) {
		f[i] = (i-1)*(f[i-1]+f[i-2]);
		t[i] = t[i-1]*i;
	}
	cin >> ti;
	while(ti--) {
		cin >> n >> m;
		long long a = t[n]/t[m]/t[n-m];
		cout << a*f[m] <<endl;
	}
	return 0;
}