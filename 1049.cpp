#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

	int n, u, d;
	while(true){
		cin >> n >> u >> d;
		if(d == 0 && u == 0 && d ==0 )
			break;

		if((n - u) % (u - d) == 0)

		cout <<  (n - u) / (u - d) * 2 + 1   <<  endl;

		else

		cout <<  (n - u) / (u - d) * 2 + 3   <<  endl;

	}
	
	return 0;
}