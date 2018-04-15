#include<iostream>
#include <cstdio>
using namespace std;


int getN(int n){

	int num = 1;

	for (int i = 1; i <= n; ++i){

		num *= i;

	}

 

 	return num;
}






int main(int argc, char const *argv[]){


	double num1, flag = 2.5;


	cout << "n e" << endl;
	cout << "- -----------" << endl;

	cout << "0 1" << endl;
	cout << "1 2" << endl;
	cout << "2 2.5" << endl;

	for (int i = 3; i <= 9; ++i){

		num1 = 1.0/getN(i);
		flag += num1;
		
		cout << i << " " ;

		printf("%10.9lf\n", flag );
	
	}


	
	return 0;
}