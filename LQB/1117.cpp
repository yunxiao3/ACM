#include <iostream>
#include<algorithm>
using namespace std;

long long a[20];

int main(int argc, char const *argv[]){

	int n, k;
	cin >> n >> k;

	a[1] = k -1;
	a[2] = k * (k - 1);

	if(n < 3)
		cout << a[n] << endl;
	else{
		for (int i = 3; i <= n; ++i)
			a[i] = (a[i - 1] + a[i - 2]) * (k - 1);

			cout << a[n] << endl;
	}



	return 0;
}