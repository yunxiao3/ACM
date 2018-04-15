#include<iostream>
using namespace std;


char N[10001];




int getRoot (int N){



	if (N < 10)
		return N;

		int Answer = 0;

		while (N != 0){

			Answer += N % 10;
			N /= 10;
		}


	getRoot(Answer);

}






int main(int argc, char const *argv[]){
	
	int sum ; 

	while (true){

		sum = 0;

		cin >> N;
		if ('0' == N[0])
			break;

		for (int i = 0; '\0' != N[i]; ++i){
			
			sum += N[i] - '0';
		}





		cout << getRoot(sum) << endl ;



	}



	return 0;
}