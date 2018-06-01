#include<iostream>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char const *argv[]){

	string br = "--------------------------------------------------------------------------------\n";
	int n = 0;

	char input[85];

	while (cin >> input){

		if (strcmp(input,"<br>") == 0){
			cout << endl;
			n = 0;
		}
		else

			if (strcmp(input,"<hr>") == 0){
				if (n!=0) cout << endl;
				cout << br;
				n = 0;
			}
			else{

				
				if(n + strlen(input) < 80){

					if(n != 0){
						cout<<" " << input;
						n = n + strlen(input) + 1; 
					}
					else{
						cout << input ;
						n = strlen(input) ; 
					}
				}

				else{

					cout<< endl << input;
					n = strlen(input); 
				}

			}
	}


	cout <<endl;

	
	return 0;
}