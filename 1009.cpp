#include <iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct Node{
	int j;
	int f;
}node[1005];

bool cmp(Node a, Node b){
	return (double) a.j / a.f > (double) b.j / b.f;
}

int main(int argc, char const *argv[]){

	int M, N;

	while(cin >> M >> N && M != -1  && N != -1){

		for (int i = 0; i < N; ++i){
			cin >> node[i].j >> node[i].f;
		}

		sort(node, node + N, cmp);

		double ans = 0;
		for (int i = 0; i < N; ++i){
				
				if (M >= node[i].f){
					ans += node[i].j;
					M -= node[i].f;
				}

				else{
					ans += (double)node[i].j / node[i].f * M;
					break;
				}
		}

		printf("%.3lf\n",ans );
	}

	

	return 0;
}