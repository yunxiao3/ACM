#include <iostream>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[]){

	int t;
	cin >> t;
	while(t--){
		double N, X;
		cin >> N;
		int answer;
		X = N * log10(N); 
		X -= (long long)X;
		cout << (long long ) pow(10,X) << endl;
	}

	return 0;
}