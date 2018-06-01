
#include<iostream>
using namespace std;

const int MAX = 1000005;
int luck[MAX];


void init(int pre, int end){

	int start = luck[pre];
	int k = pre + 1;

	for (int i = pre + 1; i <= end; ++i){
		if (i % start != 0){
			luck[k] = luck[i];
			k++;
		}	

	}

	if (pre <= end)
		init(++pre, end);

}



int main(int argc, char const *argv[]){

	int n, m;  cin >> n >> m;



	for (int i = 1; i <= m ; i ++){
		luck[i] = i * 2 - 1;		
	}


	init(2, m );

	int count = 0;

	// for (int i = 0; i < m / 2; ++i)
	// {
	// 	cout << luck[i] << " ";
	// }

	for (int i = 1; i < m / 2 + 1; ++i)
		if (luck[i] > n && luck[i] < m){
			// cout << luck[i] << " ";
			count ++;
		}

			cout<<count<<endl;


	
	return 0;
}