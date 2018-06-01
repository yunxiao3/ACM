#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int num[55][55];

int main(int argc, char const *argv[]){
	
	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> num[i][j];

	int max = N * N;
	int min1[2], min2[2], flag, X, Y;
	int ans = 0;

	flag = 1;
	for (int i = 1; i <= N; ++i){
		if(flag){
			for (int j = 1; j <= N; ++j)
				if(num[i][j] == max){
					flag = 0;
					X = i;
					Y = j;
					break;
				}
		}
	}

	// cout << X << " " << Y <<  endl; 

	while(max > 1){
		flag = 1;
		for (int i = 1; i <= N; ++i){
			if(flag){
				for (int j = 1; j <= N; ++j)
					if(num[i][j] == max- 1){
						flag = 0;
						min1[0] = i;
						min1[1] = j;
						break;
					}
			}
		}
	
		flag = 1;
		for (int i = 1; i <= N; ++i){
			if(flag){
				for (int j = 1; j <= N; ++j)
					if(num[i][j] == max- 2){
						flag = 0;
						min2[0] = i;
						min2[1] = j;
						break;
					}
			}
		}



		int max1 = (abs(X - min1[0]) + abs(Y - min1[1])) * (abs(X - min1[0]) + abs(Y - min1[1]));
		int max2 = (abs(X - min2[0]) + abs(Y - min2[1])) * (abs(X - min2[0]) + abs(Y - min2[1]));
		int zhong = (abs(min1[0] - min2[0]) + abs(min1[0] - min2[1])) * (abs(min1[0] - min2[0]) + abs(min1[0] - min2[1]));

		if(max2 > zhong + max1){
			ans += max2;
			X = min2[0];
			Y = min2[1];
			max = max - 2;
		}



		else{
			ans += max1;
			X = min1[0];
			Y = min1[1];
			max = max - 1;
		}


		// cout << ans<< max<< endl;

	}

	cout << ans << endl;


	
	return 0;
	
}