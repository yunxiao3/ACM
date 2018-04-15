#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> temp, ans;
int arrary[4] = {2,3,3,4};
int V = 6, K = 2, maxSq;




int DFS(int index, int sum, int n, int sq){

	if (sum == V && n == K){
		if (sq > maxSq){
			maxSq = sq;
			ans = temp;
		}


		
		return 0;
	}


	if (sum > V || index == 4 || n > K)
		return 0;

	temp.push_back(arrary[index]);

	DFS(index + 1, sum + arrary[index], n + 1, sq + arrary[index] * arrary[index]);

	temp.pop_back();

	DFS(index + 1, sum, n, sq);



};




int main(int argc, char const *argv[]){

	DFS(0,0,0,0);

	cout << maxSq;

	for (int i = 0; i < ans.size(); ++i){

	
		cout << ans.at(i) ;
	}

	
	return 0;
}





















































/*int num = 1;

int maxV = 0, n = 5, V = 8;
	
int weight[5] = {3, 5, 1, 2, 2}, value[5] = {4, 5, 2, 1, 3};

int DFS(int index, int sumC, int sumV){

	// cout << num ++ << endl;

	if (index == n)
		return 0;


	DFS(index + 1, sumC, sumV);

	if ( sumC + weight[index] <= V ){

		if (sumV + value[index] > maxV)
			maxV = sumV + value[index];

		DFS(index + 1, sumC + weight[index], sumV + value[index]);
	}


}


int main(int argc, char const *argv[]){


	// cin >> n >> V;


	/*for (int i = 0; i < n; ++i)
		cin >> weight[i];
	
	for (int i = 0; i < n; ++i)
		cin >> value[i];
	

	DFS(0,0,0);

	cout << maxV << endl;

	return 0;
}*/