#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[50010][50];
struct node{
	int e;
	node *next[26];
	node(){
		e = 0;
		for (int i = 0; i < 26; ++i)
			next[i] = NULL;
	}
} *root;



void insert(char *s){
	int i = 0;
	node *p = root;
	while(s[i] != '\0'){
		if (!p->next[s[i] - 'a'])
			p->next[s[i] - 'a'] = new node();
		p = p->next[s[i] - 'a'];
		i++;
	}

	p -> e = 1;
}


int find(char *s){
	int i = 0;
	node *p = root;
	while(s[i] != '\0' && p -> next[s[i] - 'a']){
		p = p -> next[s[i] - 'a'];
		i++;
	}
	if(s[i] == '\0' && p -> e)
		return 1;
	return 0;
}

int main(int argc, char const *argv[]){
	root =  new node();
	int k = 0;
	while(scanf("%s",s[k]) != EOF){
		insert(s[k]);
		k++;
	}
	for (int i = 0; i < k; ++i){
		int j = strlen(s[i]);
		char s1[100],s2[100]; 
		for (int l = 1; l < j - 1; ++l){
			int m,n,o;
			for (m = 0; m < l; ++m)
				s1[m] = s[i][m];
			s1[l] = '\0';
			for (n = l,o = 0; n < j; ++n,o++)
				s2[o] = s[i][n];
			s2[o] = '\0';
			if(find(s1)&&find(s2)){
				printf("%s\n",s[i]);
				break;
			}
		}
	}
	return 0;
}