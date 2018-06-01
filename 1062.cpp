#include <iostream>
#include<cstring>
using namespace std;

char word[1000];
char buffer[2];

int main(int argc, char const *argv[]){

	int N;  cin >> N; cin.getline(buffer,2);

	while(N--){

		cin.getline(word,1000);

		int pre = 0, pos = 0;

		for (int i = 0; i < strlen(word); ++i){

			if (word[i] == ' ' ){
				
				pos = i - 1;
				for (int j = pos; j >= pre ; --j){
					
					cout << word[j];
				}

				cout << " ";

				pre = i + 1;
			}

			if (i == strlen(word) - 1 ){
				
				pos = i ;
				for (int j = pos; j >= pre ; --j){
					
					cout << word[j];
				}

		
			}


			
		}


		cout << endl;



	}


	
	return 0;
}