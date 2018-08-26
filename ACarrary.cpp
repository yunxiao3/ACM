#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e6+100;
int a[maxn][26],v[maxn];
int size;
void init(){
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
	size = 0;
}

void insert(char *s){
	int len = strlen(s);
	int root = 0;
	for (int i = 0; i < len; ++i){
		int index = s[i] - 'a';
		if(!a[root][index])
			a[root][index] = ++size;
		root = a[root][index];
	}
	v[root] ++;
}


int query(char *s){
	int len = strlen(s);
	int root = 0;
	for (int i = 0; i < len; ++i){
		int index = s[i] - 'a';
		if(!a[root][index]){
			return 0;
		}
		root = a[root][index];
	}
	return v[root];
}



int main(int argc, char const *argv[]){
	init();
	char str[50];
	for (int i = 0; i <= 3; ++i){
		cin >> str;
		insert(str);
	}
	// cout << size << endl;
	for (int i = 0; i <= 3; ++i){
		cin >> str;
		cout << query(str) << endl;
	}
	return 0;
}