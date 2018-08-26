#include<iostream>
using namespace std;
long long  a[50];
int main(int argc, char const *argv[]){
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	for (int i = 4; i <= 50; ++i)
		a[i] = a[i - 2] + a[i - 1];
	
	int n;
	while(cin >> n)
		cout << a[n] << endl;
		
	return 0;
}

