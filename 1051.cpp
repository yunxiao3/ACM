#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
	int l; 
	int w;
	bool flag;
};

int cmp(Node a,Node b){
	return a.l < b.l || a.l == b.l && a.w < b.w;
}

int main(int argc, char const *argv[]){
	int t;
	int n;
	cin >> t;
	while(t--){
		cin >> n;
		Node node[5010];
		for (int i = 0; i < n; ++i){
			node[i].flag = false;
			cin >> node[i].l >> node[i].w;	
		}
		sort(node, node + n, cmp);
		int num = 0;
		for(int i = 0; i < n; i++){
			if(node[i].flag)
				continue;
			num++;
			for(int k = i, j = i + 1; j < n; j ++){
				if(node[j].flag)
					continue;
				if(node[k].l <=  node[j].l && node[k].w <= node[j].w){
					k = j;
					node[k].flag = true;
				}	
			}
		}

		cout << num <<endl;

	}
	
	return 0;
}