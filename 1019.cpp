#include <iostream>
using namespace std;

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(int argc, char const *argv[]){
	

	int M, N, ans, num; 
	cin >> M;

	while (M --){

		
		cin >> N >> ans;
		for (int i = 1; i < N; ++i){
			cin >> num ;
			ans = ans / gcd(ans, num) * num;			
		}
		cout << ans <<endl;
	
	}


	return 0;
}


