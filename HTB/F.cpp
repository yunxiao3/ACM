#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num[10005];
vector<int> inq[10005];


int main(int argc, char const *argv[]){

	int m, n;
	cin >> m >> n;
	int u, v;
	int flag = -1;
	for (int i = 0; i < m; ++i){

			cin >> u >> v;
			if(num[u] == 0 && num[v] == 0){
			flag++;
			inq[flag].push_back(v);
			inq[flag].push_back(u);
			}
			else{

				int is = 1;

				if(num[u] != 0)
					for (int i = 0; i <= flag; ++i){
						if(is)
						for(int j = 0; j < inq[i].size(); j++)
							if(inq[i][j] = u){
								inq[i].push_back(v);
								is = 0;
								break;
							}
					}
				else
					for (int i = 0; i <= flag; ++i){
						if(is)
						for(int j = 0; j < inq[i].size(); j++)
							if(inq[i][j] = v){
								inq[i].push_back(u);
								is = 0;
								break;
							}
					}
			}


			num[u] = 1;
			num[v] = 1;
		}	



		int s = n - flag - 1;

		int size[10000];
		for (int i = 0; i < flag; ++i){
			size[i] = inq[i].size();
		}

		int ans = 0;
		for (int i = 0; i < flag; ++i){
			
		}



	
	return 0;
}