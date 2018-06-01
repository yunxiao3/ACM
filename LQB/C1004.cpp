#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){

	
	int N; 

	while(cin >> N && N != 0){

		int a = 1, b = 0, c = 0, d = 0;
		for (int i = 1; i < N; ++i){
			a += b;
			b = c; 
			c = d; 
			d = a;
		}
		cout << a + b + c + d << endl;
	}
	return 0;
}