#include <iostream>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[]){


	int T; cin  >> T;

	for (int i = 0; i < T; ++i){
		
		int  year, num; cin >>year>>num;
		int times = 1;
		while(!(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)){
			year++;
		}

		while(times < num ){
			year += 4;
			if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				times ++;
		}

		cout << year <<endl;
	}


	return 0;
}