#include<iostream>
#include<algorithm>
using namespace std;

int a[1005];
int b[1005];
int n;
int cmp(int a, int b){
	return a > b;
}


ping(int i, int j){
	int num = 0;
	int p = 0;
	for (; j < n; ++j){
		if(a[i] > b[j]){
			i ++;
			num++;
		}
		if(a[i] == b[j]){


		}


	}

}


int main(int argc, char const *argv[]){
	while(cin >> n && n){		
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		int num = 0;
		int p = 0;
		for (int i = 0, j = 0; j < n; ++j){
			if(a[i] > b[j]){
				i ++;
				num++;
			}
			if(a[i] == b[j]){
				ping(i + 1, j + 1)
			}


		}
		cout << 2 * num - n  * 200 << endl;
	}
	return 0;
}