/*#include<iostream>
using namespace std;


int Fibonacci(int n){

	if (n == 0)
		return 7;
	if (n == 1)
		return 11;


	return Fibonacci(n - 1) + Fibonacci(n - 2);

}



int main(int argc, char const *argv[]){


	int N;
	int num1 = 2, num2 = 3;


	while(1){


		for ( N = 0; N <  100; ++N){



			if (Fibonacci(N) % 3 == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		}

		
	}



	
	return 0;
}


打表找规律






*/




#include<iostream>
using namespace std;


int main(int argc, char const *argv[]){


	int N; 

	while(cin >> N){



		if (N % 4 == 2)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}
	
	return 0;
}