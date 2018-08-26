#include <iostream>
using namespace std;

long long  a[2][60];

int main(){
	a[0][1] = a[1][1] = 1;
	int t;
	cin >> t;
	while(t--){
		int a1, b;
		cin >> a1 >> b;

		if(a1 % 2 == 0){
			b = b - a1 + 2;
			for (int i = 2; i < 50 ; ++i){
				a[1][i] = a[1][i - 1] +  a[0][i - 1];
				a[0][i] = a[1][i] + a[0][i - 1];
				
			}

			if(b % 2 == 0)
				cout << a[1][b / 2] << endl;
			else
				cout << a[0][b/2] << endl;
		}

		else{

			if(a1 > 1){
				b = b - a1 + 1;
			}
		
			for (int i = 2; i < 50 ; ++i){
				a[0][i] = a[1][i - 1] +  a[0][i - 1];
				a[1][i] = a[0][i] + a[1][i - 1];
			
			}
			if(b % 2 == 0)
				cout << a[1][b / 2] << endl;
			else
				cout << a[0][b/2 + 1] << endl;
			}
	}	
	return 0;
}