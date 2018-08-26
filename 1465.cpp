#include<iostream>
using namespace std;
 
int main() {
	int n;
	long long d[21] = {0,0,1};//将d[0],d[1],d[2]初始化
	for(int i=3;i<=20;i++) {
		d[i] = (i-1)*(d[i-1]+d[i-2]);
	} 
	while(cin >> n) {
		cout << d[n] <<endl;
	}
	return 0;
}