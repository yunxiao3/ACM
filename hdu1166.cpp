#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

int n, tree[100000];

int low_bit(int x){
	return x & -x;
}

void add(int i, int x){
	while(i <= n){
		tree[i] = tree[i] + x;
		i += low_bit(i);
	}	
}


int sum(int i){
	int sum = 0;
	while(i>0){
		sum += tree[i];
		i -= low_bit(i);
	}
	return sum;
}



int main(int argc, char const *argv[]){

	int t,temp,Case=1;
	cin >> t;
	while(t--){
		memset(tree,0,sizeof(tree));
		cin >> n;
		cout << "Case " << Case ++<< ":"<<endl;
		for (int i = 1; i <= n; ++i){
			scanf("%d",&temp);
			add(i,temp);
		}

		char str[10];

		while(cin >> str && strcmp(str,"End") != 0){
			int a,b;
			scanf("%d%d",&a,&b);
			if(str[0] == 'Q')
				printf("%d\n", sum(b) - sum(a-1));
			if(str[0] == 'A')
				add(a,b);
			if(str[0] == 'S')
				add(a,-b);
		}

	}




	
	return 0;
}