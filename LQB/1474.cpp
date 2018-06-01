#include<iostream>  
#include<cstdio>
using namespace std; 

int ans[1000];

int main(int argc, char const *argv[]){

	int n = 100;
	int temp = 0;
	cin >> n;
	ans[0] = 1;

	for (int j = 1; j <= n; ++j)
		for (int i = 0; i < 1000; ++i){
			ans[i] *= j;
			ans[i] += temp;
			temp = 0;
			if(ans[i] >= 10000){
			temp = ans[i] / 10000;
			ans[i] %= 10000;
			// cout<< temp << " ";
			}
		}

	int max = 0;

	for (int i = 1000; i >= 0; --i){
				if(ans[i] != 0){
					max = i;
					break;
				}
			}


		cout << ans[max];


	for (int i = max - 1; i >= 0; --i){
				if(ans[i])
					printf("%04d",ans[i]);
				else
					cout << "0000";
			}


	cout << endl;
	return 0;
}