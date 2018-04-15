#include <algorithm>
#include<iostream>
#include<cstring>
using namespace std;


int array[1005];



int main(int argc, char const *argv[]){

	int N, T;

	cin >> N;

	for (int i = 0; i < N; ++i){
		
		cin >> T;

		for (int i = 0; i < T; ++i)
				cin >> array[i];							


		sort(array, array + T);


		for (int i = 0; i < T - 1; ++i)
				cout << array[i] << " ";

		cout << array [T - 1] <<endl;
	}



	
	return 0;
}