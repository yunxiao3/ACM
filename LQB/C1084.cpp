#include<iostream>
using namespace std;

const int MAX = 1000000;
int prime[MAX];

int main(int argc, char const *argv[]){

	int N; cin >> N;

	prime[1] = 1;

	for (int i = 4; i <= N; i += 2)
		prime[i] = 1;

	for (int i = 3; i <= N / 2; i++){
		if (prime[i] != 1)
			for (int j = i * 2; j <= N; j += i)
				prime[j] = 1;
				
	}

	for (int i = 1; i <= N; i ++	)
		if (prime[i] == 0)
			cout << i << endl;



	
	return 0;
}