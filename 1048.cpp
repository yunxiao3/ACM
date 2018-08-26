#include <iostream>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[]){

	char a[1200], b[1200];
	while(cin.getline(a,200)){

		if(strcmp(a,"ENDOFINPUT") == 0){
			// cout << endl;
			break;
		}
		if(strcmp(a,"START") == 0)
			continue;
		if(strcmp(a,"END") == 0){
			cout << b;
			continue;
		}

		int i;
		for ( i = 0; a[i] != '\0'; ++i){
			if(a[i] <= 'Z' && a[i] >= 'A'){
				if(a[i]  > 'E' )
					b[i] = a[i] - 5;
				else
					b[i] = a[i] + 21;
			}

			else
				b[i] = a[i];
		}

		b[i] = '\n';
		b[i+1] = '\0';


	}	
	return 0;
}