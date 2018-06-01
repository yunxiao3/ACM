#include<iostream>
using namespace std;


char map[150][150];
int centerX;
int centerY;

void draw(int n){

	int x1 = centerX + 2 * n + 2;
	int x2 = centerX - 2 * n - 2;
	int y1 = centerY + 2 * n + 2;
	int y2 = centerY - 2 * n - 2;

	for (int i = centerY - 2 * n; i <= centerY + 2 * n  ; ++i){
		map[x2][i] = '$';
	}

	for (int i = centerY - 2 * n; i <= centerY + 2 * n  ; ++i){
		map[x1][i] = '$';
	}


	for (int i = centerX - 2 * n; i <= centerX + 2 * n  ; ++i){
		map[i][y1] = '$';
	}

	for (int i = centerX - 2 * n; i <= centerX + 2 * n  ; ++i){
		map[i][y2] = '$';
	}


	int lx[] = {centerX + 2 * n, centerX + 2 * n, centerX - 2 * n, centerX - 2 * n};
	int ly[] = {centerY + 2 * n, centerY - 2 * n, centerY + 2 * n, centerY - 2 * n};
	int fx[] = {1,1,-1,-1};
	int fy[] = {1,-1,1,-1};

	for (int i = 0; i < 4; ++i){
		int newX = lx[i];
		int newY = ly[i];
		map[newX][newY] = '$';
		map[newX + fx[i] ][newY] = '$';
		map[newX][newY  +  fy[i]] = '$';
				
	}



}

int main(int argc, char const *argv[]){
	
	int N; cin >> N;
	centerX = N * 2 + 3;
	centerY = N * 2 + 3;

	

	for (int i = centerX - 2; i <= centerX + 2 ; ++i){
		map[i][centerY] = '$';
	}

	for (int i = centerY - 2; i <= centerY + 2; ++i){
		map[centerX][i] = '$';
	}




	for (int i = 1; i <= N; ++i)
		draw(i);


	for (int i = 1; i <= 4 * N + 5 ; ++i){
		for (int j = 1; j <= 4 * N + 5 ; ++j)
			if (map[i][j] == '$')
				cout << '$';
			else
				cout << '.';	
		cout << endl;
	}


	
	return 0;
}