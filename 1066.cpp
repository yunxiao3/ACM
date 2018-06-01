#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){


	int num, ans ;

	while (cin >> num){

		ans = 1;

		for (int i = 1; i <= num ; ++i){

			ans *= i ;
			while(ans % 10 == 0){
				ans /= 10;
			}

			ans %= 10000000;
		
		}

		cout << ans % 10 << endl;
	}
	
	return 0;
}