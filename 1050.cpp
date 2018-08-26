#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


struct Node{
	int x;
	int y;
	bool flag;
}node[500];

int cmp(Node a, Node b){
	return a.y < b.y;
}

int main(int argc, char const *argv[]){

	int T;
	while(T--){
		int n, x, y;
		cin >> n;
		for (int i = 0; i < n; ++i){
			node[i].flag = false;
			cin >> x >> y;
			if(y < x){
				int temp = x;
				x = y;
				y = x;
			}
			if(x % 2 == 0)
				x -= 1;
			if(y % 2 == 0)
				y -= 1;
			node[i].x = x;
			node[i].y = y;
		}

		sort(node, node + n, cmp);

		int num = 0;

		for (int i = 0; i < n; ++i){
			if(node[i].flag)
					continue;
			num++;
			for (int k = i, j = i + 1; j < n; ++j){
				if(node[j].flag)
					continue;
				if(node[j].x > node[k].y){
					// cout << node[j].x << " "<< node[k].y << endl;
					k = j;
					node[k].flag = true;
				}
			}

		}
		cout << num * 10 << endl;
	}
	return 0;
}