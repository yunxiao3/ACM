#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

int map[3][4];
const int dx[]={0,-1,-1,-1};
const int dy[]={-1,-1,0,1};
int ans = 0;
const int X[4] = {0,-1,-1-1};
const int Y[4] = {-1,-1,0,1};

bool inq[10] = {false};
int num[10];


/*bool check(int x, int y, int n){


		// if ( abs(map[x - 1][y + 1] - n) == 1 )
		// 	return false;


	for (int i = 0; i < 4; ++i){
		
		int newX = x + X[i];
		int newY = y + Y[i];

		if (newY > 3 || newY < 0 || newX > 2 || newX < 0)
			continue;

		if ( abs(map[newX][newY] - n) == 1 )
			return false;
	}

	return true;
}
	*/


bool check(int x,int y,int n)
{
    for (int i=0;i<4;i++) {
        int xx=x+X[i],yy=y+Y[i];
        if (xx<0||yy<0||xx>2||yy>3) continue;
        if (abs(n-map[xx][yy])==1) return false;
    }
    return true;
}

int a = 0;


int DFS(int x, int y){

	if(x == 2 && y == 3){
		ans ++ ;
if (a < 10)
{
	
		for (int i = 0; i < 3; ++i){
		for(int j = 0 ; j < 4; ++j)
			cout<< map[i][j] << " " ;
		cout << endl;
	}
	a ++;
}
		return 0;
	}

	for (int i = 0; i < 10; ++i){
		
		if(  !inq[i] && check(x, y, i) ){
		
			inq[i] = true;
			map[x][y] = i;

			if (y + 1 <= 3)
				DFS(x, y + 1);
			else
				DFS(x + 1, 0);
		

			inq[i] = false;
			map[x][y] = -120;
		}




	}




}




int main(int argc, char const *argv[]){


	for (int i = 0; i < 3; ++i){
		for(int j = 0 ; j < 4; ++j)
			map[i][j] = -120;
	}

	



	DFS(0,1);
	cout << ans << endl;
	

	

	return 0;
}