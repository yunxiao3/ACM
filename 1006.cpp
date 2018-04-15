#include<iostream>
using namespace std;

int main(int argc, char const *argv[]){
	
	int second, minute, hour;
	double sdegree, mdegree, hdegree;

	for (int i = 0; i < 86400; ++i){
		
		if (second == 60)
			second = second % 60;
		if (minute == 60)
			minute = minute % 60;
		
		sdegree = 360 / second;
		mdegree = 360 / minute;
		hdegree = 360 / 12;


	}




	return 0;
}

