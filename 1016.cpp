#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

const int N = 21;
int length;
bool inq[N] = {false};
int number[N];
int ans[N];

struct node{
	int len;
 	int ans[N];
 }Node; 




bool is(int a){

	for (int i = 2; i < a / 2; ++i)
		if(a % i == 0)
			return false;
	return true;
}



int  DFS(int num){

		inq[num] = true;
		Node.len ++;
		// cout << Node.len;
		Node.ans[Node.len] = num;
		
		if(Node.len == length){

			if (  is(Node.ans[Node.len] + 1) ){
				
				cout << 1;
				for (int i = 2; i <= length; ++i){
					cout <<" "<< Node.ans[i];
				}
				
				cout<<endl;

			}

			return 0;
		}


		for (int i = 1; i <= length; ++i){

			if( !inq[i] &&  is(Node.ans[Node.len] + i) ){

				DFS(i);

				inq[i] = false;
				Node.len --;
				
			}

		}


} 





int main(int argc, char const *argv[]){

	



		int times = 1;

		while( cin >> length){	

			Node.len = 0;	

			for (int i = 1; i <= length; ++i){
				
				number[i] = i ;
				inq[i] = false;
			}


			cout << "Case "<<times<<":"<<endl;


			DFS(1);
			cout << endl;

			times++ ;
		}







	
	return 0;
}