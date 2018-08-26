#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 1e6+100;
char s[maxn];

int main(int argc, char const *argv[]){
	int n, p;
	scanf("%d%d",&n,&p);
	scanf("%s",s);
	p = 'a' + p - 1; 
	int i, j;
	for (i = n - 1; i >= 0; --i){
		for (j = s[i]+1; j <= p ; ++j){
			if(i >= 1 && j == s[i-1] || i >= 2 && j == s[i-2])
				continue;
			break;
		}
		if(j <= p){
			s[i] = j;
			break;
		}
	}
	if(i == -1)
		printf("NO\n");
	else{
		for (int k = i+1; k < n; ++k){
			for (j = 'a'; j <= p ; ++j){
				if(k >= 1 && j == s[k-1] || k >= 2 && j == s[k-2])
					continue;
				s[k] = j;
				break;
			}
		}
		printf("%s\n",s);
	}
	return 0;
}