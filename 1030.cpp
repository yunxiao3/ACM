#include <iostream>
#include<cmath>

using namespace std;

int main(int argc, char const *argv[]){


	int N, M;
	cin >> N >> M;
	int Nr = 1, Mr = 1;
	int Nc, Mc;
	while(pow(Nr,2) < N){
		Nr++;
	}

	while(pow(Mr,2) < M ){
		Mr++;
	}


	Nc = N - pow(Nr - 1,2);
	Mc = M - pow(Mr - 1,2);



	if (Mr == Nr)
		cout << (M > N ? Mc - Nc : Nc - Mc)  <<endl;

	cout << Mc <<" " << Mr<< " 	" << Nc << " "<< Nr << endl;



	
	return 0;
}