#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int N = 5;

int maze[N][N] = {{0,0,0,0,0},{0,1,0,1,0},{0,1,2,1,0},{0,1,1,1,0},{0,0,0,2,1}};
bool inq[N][N] = {false};


struct node{

	int x, y;
	int step;
	int road[100][2];
}Node;



bool test(int x, int y){


	if(x >= N || y >= N || x < 0 || y < 0 || maze[x][y] == 1 || inq[x][y] == true)
		return false;
	return true;
}




int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};



int BFS(int x, int y, int dx, int dy){

	queue<node> Q;

	Node.x = x;
	Node.y = y;
	Node.step = 0;
	Node.road[0][0] = x;
	Node.road[0][1] = y;

	Q.push(Node);

	while(!Q.empty()){

		node top = Q.front();
		Q.pop();

		if (top.x == dx && top.y == dy){

			int step = top.step;

			for (int i = 0; i < step; ++i){

				cout << "("<< top.road[i][0] << "," <<top.road[i][1]<< ")" << " -> "; 

			}

			return step;
		}


		for (int i = 0; i < 4; ++i){
			
			int newX = top.x + X[i];
			int newY = top.y + Y[i];




			if (test(newX, newY)){
				Node.x = newX, Node.y = newY;
				Node.step = top.step + 1;
				Node.road[Node.step][0] = newX;
				Node.road[Node.step][1] = newY;
				Q.push(Node);
				inq[newX][newY] = true;
			}

		}
		
	}
}

















int main(int argc, char const *argv[]){

	int i, j, k, l;
	cin >> i >> j >> k >> l;

	cout << BFS(i, j, k, l);
	return 0;
}