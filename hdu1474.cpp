#include <iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cctype>
using namespace std;

char s[1000010];


void output (int st){

	for (int i = st; i < strlen(s); ++i){
			int num = 0;
			if(isdigit(s[i]))
				while(isdigit(s[i])){
					num += s[i] - '0';
					i++;
				}

			if(s[i] == '(')


				for (int i = 1; i < num; ++i)
					output(i);


			
		}
}



int main(int argc, char const *argv[]){
	
	int t; 
	cin >> t;
	while(t--){
		scanf("%s",s);
		
	}



	return 0;
}