



// Given an integer N(0 ≤ N ≤ 10000), your task is to calculate N!








#include<iostream>
using namespace std;





int main(int argc, char const *argv[]){
	

	int n;

	while (cin >> n){

		int A[1000] = {0};

		if (n < 0)
			continue;

			
		A[0] = 1;
		int m = 1;


		for (int i = 1; i < 10000; ++i){

			A[i] = 0;		
		}



		for (int i = 1; i <= n; ++i){
			
			for (int j = 0; j < m; ++j){
				
				A[j] = A[j] * i;
				
				if (j > 0 && A[j - 1] > 10000){

					A[j] += A[j - 1] / 10000;
					A[j - 1] =  A[j - 1] % 10000;
				}

				if (A[j] >= 10000)
					m++;
			}
		}


		for (int i = m - 1; i >= 0 ; --i){

			cout << A[i];
		}


		cout << endl;

	}


	return 0;
}