
#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){

	int N; 
	int f1 = 0, f2 = 0;
	int time;
	while (true){

		time = 0; f1 = 0; f2 = 0;
		
		cin >> N;
			
		if ( 0 == N)
			break;

		for (int i = 0; i < N; ++i){
			
			cin >> f2;

			if (f2 > f1)
				time += 6 * (f2 - f1);
			if (f2 < f1) 
				time += 4 * (f1 - f2);

			time += 5; 

			f1 = f2;
	
		}

		cout << time << endl;

	}
	



	return 0;
}