#include <iostream>
using namespace std;
int main(int argc, char const *argv[]){
	
	int n, a, b, c;
	double num;
	while(cin >> n && n){
		a = b = c =0;	
		for (int i = 0; i < n; ++i){
			cin >> num;
			if(num > 0)
				a++;
			if(num == 0)
				b ++;
			if(num < 0)
				c ++;
			}	
		
		cout << c << " " << b << " " << a <<endl;
	}
	return 0;
}