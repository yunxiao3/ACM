#include<iostream>
#include<cstring>
using namespace std;



int main(int argc, char const *argv[]){
	

	char ball[1001][15];
	char color[15];
	int count[1001];
	int flag;
	
	while (true){

		for (int i = 0; i < 1001; ++i){
			
			count[i] = 0;
		}
	
		int N;  cin >> N;

		if (N == 0)
			break;

		for (int i = 0 , n = 0; i < N; ++i)	{
				
			cin >> color;

			if (n == 0){
				strcpy(ball[n], color);
				n++;
				count[0] = 1;
				continue;
			}


			for (int j = 0; j < n; j++){


				flag = 1;

				if( strcmp( color, ball[j]) == 0 ){
					
					count[j]++;
					flag = 0;
					break;
				}
			
			}


			if (flag == 1){

				count[n] ++;				
				strcpy(ball[n], color);
				n++;

			}

		}



		int max = 0, num = 0;

		for (int i = 0; i < 1001; ++i){
			

			if (count[i] > max){
				max = count[i];
				num = i;
			}
		}


		cout << ball[num] <<endl;


	}



	return 0;
}