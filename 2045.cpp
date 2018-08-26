#include<iostream>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[]){

	long long a[50];
	a[1] = 3;
	a[2] = 6;
	a[3] = 6;
	for (int i = 4; i <= 50; ++i)
		a[i] = 2 * a[i - 2] + a[i - 1];
	int n ;
	while(cin >> n)
		cout << a[n] << endl;

	return 0;
}



