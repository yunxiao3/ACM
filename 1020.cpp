#include<iostream>
#include<cstring>
using namespace std;



int main(int argc, char const *argv[]){

	char A[10005];
	int N, len, n; 
	int flag = 0;

	cin >> N;

	// cout << "SASAS" << endl;
	
	for (int i = 0; i < N; ++i){

		cin >> A;
		int len = strlen(A);

		// cout << len << endl;
		int Character[50][26] = {0};
		char maxV = A[0];
	

		for (int i = 0; i < len; ++i){
			
			if(maxV <= A[i]){
				maxV = A[i];
				Character[flag][A[i] - 'A']++;
			}

			if(maxV > A[i]){
				flag++;
				maxV = A[i];
				Character[flag][A[i] - 'A']++;
			}

		}



		// cout << "successful" << endl;

		for (int i = 0; i <= flag; ++i){
			
			for (int j = 0; j < 26; ++j){
				
				if(Character[i][j] == 0)
					continue;
				if(Character[i][j] == 1)
					cout <<(char) (j + 'A');
				if (Character[i][j] > 1){
					cout<< Character[i][j]  <<(char) (j + 'A');
				}
			}

		}


		cout << endl;





	}





	return 0;
}