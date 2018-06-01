#include<iostream>
#include<vector>
using namespace std;

vector<int> v;


int main(){

	v.push_back(0);

	for (int i = 1; i < 1000000; i += 2){
		v.push_back(i);
	}


	int flag = 2;


	while(flag < 20){

		int d = v[flag];
		flag ++;

		for (int i = d; i < v.size(); i += d){
			
			v.erase(v.begin()+i);
			i --;
		}
	}



	for (int i = 1; i < v.size(); ++i){
		cout << v[i] << " ";
	}

}