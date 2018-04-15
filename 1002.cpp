	#include<iostream>
	#include<cstring>
	using namespace std;

	char A[1001] , B[1005];  
	int  C[1005];

	void init(){

		for (int i = 0; i <= 1000; ++i){

			A[i] = B[i] = '0';
		}
	}

	void input(){

		init();
		cin >> A >> B;
		// cout<<A<<B;
	}


	void output(){

		int lenA = strlen(A);
		int lenB = strlen(B);
		int j = 0;
		int N = lenB > lenA ? lenB : lenA;

		// cout << "N: " << N <<endl;


		int flag = 0, sum = 0;

		for (int i = N - 1; i >= 0; i-- , j++){

			sum  = B[i] - '0' + A[i] - '0' + flag; 
			flag = sum / 10;
			sum = sum % 10;
			C[j] = sum;
		}



		if (flag > 0)
			C[j] = flag;
		else
			j --;


		for (int i = 0; i < lenA; ++i){
		
			cout<<A[i];
		}


		cout << " + ";


		for (int i = 0; i < lenB; ++i){
		
			cout<<B[i];
		}


		cout << " = ";



		for (int i = j; i >= 0 ; i--){

			cout<<C[i];
		}


		cout<<endl;

		init();

	}



	int main(int argc, char const *argv[]){

		int N;
		cin>> N;
		for (int i = 1; i <= N; ++i){
			input();
			cout << "Case "<< i <<":"<<endl;
			output();
			if (i == N)
				break;
			cout<<endl;
		}

		

		return 0;
	}



