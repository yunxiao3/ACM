
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int inq[13];
int num[13];
int N;
char str[13];
char ans[13];



int DFS(int anser, int flag, int count){
		if (anser == N )
			return 1;
		for (int i = 0; i < strlen(str) && !inq[i]; ++i){
			inq[i] = 1;
			ans[count -1] = 'A' - 1 + num[i] ;
			DFS(anser * flag * pow(num[i],count), -flag, count++);
			inq[i] = 0;
		}
}



int main(int argc, char const *argv[]){

	


	while(true){
		cin >> N;
		cin >> str;
		if(N == 0 && strcmp(str,"END"))
			break;

		for (int i = 0; i < strlen(str); ++i)
			num[i] =  str[i] - 'A' + 1;

		DFS(1,1,1);


	}



	return 0;
}