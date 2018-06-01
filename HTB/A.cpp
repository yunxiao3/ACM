#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;


int main(int argc, char const *argv[]){

	int n, c, temp;
	cin >> n >> c;
	for (int i = 0; i < n; ++i){
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < n; ++i){
		cout << v[i];
	}




	
	return 0;
}