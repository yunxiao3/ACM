#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int sum;
	int i;

	while(cin >> n){
		for (i = 0, sum = 0; i <= n; ++i){
			
			sum += i;
		}

		cout << sum<<endl<<endl;

	}


	return 0;
}