#include <iostream>
#include<algorithm>
using namespace std;
char a[100],b[100],c[100];
int main(int argc, char const *argv[]){

	int t;
	cin >> t;
	int ca = 1;
	while(t--){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		for (int i = 0; i < m; ++i)
			cin >> c[i];
		int mod = a[1] - b[1];

		cout << "Case #" << ca << ":";


		for (int i = 0; i < m; ++i)
			if(c[i] + mod >= 'A' && c[i] + mod <= 'Z')
				cout <<(char) (c[i] + mod);
			else
				if(c[i] + mod < 'A')
					cout <<(char) ('Z' - ('A' - (c[i] + mod)) + 1);
				else
					cout << (char) ('A' +  ('Z' - (c[i] + mod)) - 1);
		cout << endl;

		ca ++;
	}

	return 0;
}