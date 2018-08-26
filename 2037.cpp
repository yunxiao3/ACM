#include <iostream>
#include<algorithm>
using namespace std;

struct Node{
	int x;
	int y;
}node[150];

int cmp(Node x, Node y){
	return x.y < y.y;
}


int main(int argc, char const *argv[]){

	int t;
	while(cin >> t && t){

		for(int i = 0; i < t; i ++)
			cin >> node[i].x >> node[i].y;
		sort(node, node + t, cmp);
		int num = 1;
		for(int i = 1, j = 0; i < t; i++){
			if( node[j].y <= node[i].x ){
				num ++;
				j = i;
			}
		}

		cout << num << endl;
	}

	return 0;
}