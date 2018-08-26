#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s1,s2;

int main(int argc, char const *argv[]){
	while(cin >> s1 >> s2){
		s1 = s1 + s1 +s1;
		// cout << s1 << " " << s2 <<endl;
		if(s1.find(s2) != -1){
			// cout << s1.find(s2) << endl;
			printf("yes\n");
		}
		else
			printf("no\n");

	}

	return 0;
}