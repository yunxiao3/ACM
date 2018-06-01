#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

char str[50];
int inq[50];
int win[4];


void init(){
	win[2] = 0;
	win[0] = 0;

	for (int i = 0; i < strlen(str); ++i){
		if(str[i] == '*')
			inq[i] = 0;
		else
			inq[i] = 1;
	}

}



int cmp(int flag){
	for (int i = 0; i < strlen(str) - 2; ++i){
		if(str[i] == 'L' && str[i+1] == 'O' && str[i+2] == 'L')
			win[flag + 1] = 1;
		return 1;
	}

	return 0;
}


void judge(int flag){

	for (int i = 0; i < strlen(str); ++i){
		if(!inq[i]){
			inq[i] = 1;
			str[i] = 'L';
			cmp(flag);
			judge(-flag);
			str[i] = 'O';
			cmp(flag);
			judge(-flag);
			inq[i] = 0;
			str[i] = '*';

		}
	}

}




int main(int argc, char const *argv[]){

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> str;
		init();
		judge(1);
		cout << win[2] - win[1]<<endl;

	}
	
	return 0;
}