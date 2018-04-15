	#include<iostream>
	#include<cstring>
	using namespace std;


	int A, B;

	int value[100000005];


	int function( int N ){

		int n1, n2;

		if (N <= 2 )
			return 1;



		if ( value[N - 1] != 0){
		
			n1 = function( N - 1 );
		}
		else
			n1 = value[N - 1] = function(N - 1);


		n2 = value[N - 2];



		return  ( n1 * A + n2 * B ) % 7; 
	} 




	int	main(int argc, char const *argv[]){

			value[1] = value [2] = 1;
			A = 1; B = 2;


		while (true){

			int N;
			cin >> N;

		for (int i = 0; i < N; ++i){

			cout<< i<<" = " << function(i) << endl;
		}


		
		
		
		}

		return 0;
	}