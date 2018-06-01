#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;



int map[3][4] = {-10};
bool inq[3][4] = {false};
bool num[10] = {false};
int X[8] = {0,0,1,-1,-1,-1,1,1};
int Y[8] = {1,-1,0,0,1,-1,1,-1};
int ans = 0;


struct node{
	int x;
	int y;
}Node;


queue<node> Q;


int sub(int x, int y){

	if (x > y)
		return x - y;
	else 
		return y - x;
}





bool judge(int x, int y, int n){



	for (int i = 0; i < 8 ; ++i){
		
		int newX = x + X[i];
		int newY = y + Y[i];

		if(newX >= 0 && newX < 3 && newY >= 0 && newY < 4)
			if( sub(map[newX][newY], n) == 1)
				return false;
	}



}



int BFS(int x, int y){

	if(x == 2 && y == 2){
		ans ++;
		return 0;
	}

	for (int i = 0; i < 10; ++i){

		if (!inq[i]){

			num[i] = true;
			map[x][y] = i;

			if(judge(x,y,i)){

			if(y + 1 < 4)  
                BFS(x, y + 1);  
             else  
                BFS(x + 1, y);
			}	

		}

		num[i] = false;
		
	}
}




int main(int argc, char const *argv[]){
	int s;
	cin >> s;
	BFS(0,1);
	cout << ans;
	
	return 0;
}