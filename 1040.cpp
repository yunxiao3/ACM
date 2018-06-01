#include <iostream>
#include<algorithm>
using namespace std;

int a[10000];

int main(int argc, char const *argv[]){
		
		int n, m;
		cin >> n;
		for (int i = 0; i < n; ++i){
			cin >> m;
			for( int j = 0; j < m; j++)
				cin >> a[j];
			sort(a,a+m);

			cout << a[0];
			for(int j = 1; j < m; j++)
				cout<<" " << a[j];

			cout<<endl;

		}



	return 0;
}