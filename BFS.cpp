#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int N = 4;


struct  node{

	int x;
	int y;
}Node;

int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

int matrix[N][N] = {  {1,0,0,1}, {0,0,0,1},{0,0,0,0},{1,1,1,1}};
bool inq[N][N] = {false};



bool judge(int x, int y){

	if (x >= N || x < 0 || y < 0 || y >= N || matrix[x][y] == 0 || inq[x][y] == true)
		return false;

	return true;
}



void BFS(int x, int y){

	queue<node> Q;
	Node.x = x;
	Node.y = y;
	Q.push(Node);
	inq[x][y] = true;

	while(!Q.empty()){
		node top = Q.front();
		Q.pop();

		for (int i = 0; i < 4; ++i){
			
			int newX = top.x + X[i];
			int newY = top.y + Y[i];

			if (judge(newX, newY)){
				Node.x = newX;
				Node.y = newY;
				Q.push(Node);
				inq[newX][newY] = true;
			}

		}


	}

}







int main(int argc, char const *argv[]){
	
	int ans = 0;

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			
			if (matrix[i][j] == 1 && inq[i][j] == false){
				ans++;
				BFS(i,j);

			}

			// cout << matrix[i][j];


			

		}


		// cout << endl;
	}
	cout << ans << endl;

	return 0;
}