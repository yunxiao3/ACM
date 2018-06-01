
#include<iostream>
#include<cstring>
using namespace std;

int main(){

	int num ,M = 0;
	int N[1000];
	int m[100];
	memset(N,0,sizeof(int)*1000);
	/*for (int i; i<100; i++)
		cout<<m[i];5
	*/
	cin>>num;
	for (int i = 0, j; i < num; i++){
		cin>>j;
		N[j]++;
		//cout<<N[j];
	}
	for (int i = 0; i < 1000; i++){


		if (N[i] != 0){
		///	cout<<i<<" s";
						m[M] = i;
			M++;
		}


	}

//	cout<<"AAA"<<M<<"ABC"<<endl	;

	for(int i = 0,temp; i < M-1; i++){

		for(int j = i+1; j < M; j++ ){

			if (m[i] > m[j]){

				temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
		}

	}

	cout<<M<<endl;

	for(int i; i < M ;i++){
		cout<<m[i]<<" ";
	}
	cout<<endl;

}

