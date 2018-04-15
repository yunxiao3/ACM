#include<iostream>
#include<cstring>
#include <queue>

using namespace std;


struct  node{

	int data;

}a[10];


int main(int argc, char const *argv[]){


	queue<node> q;


	for (int i = 0; i < 3; ++i){
			
			a[i].data = i + 10; 
			q.push(a[i]);
		}	




	qfront().data = 100;



	cout << a[0].data;

		
		return 0;
}