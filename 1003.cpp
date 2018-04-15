// I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.

/*

#include<iostream>
using namespace std;

int arrary[100002];



void output(int N){

	int flag1 = 0, flag2 = 0, sum1 = 0, sum2 = arrary[0];

	for (int i = 0; i < N; ++i){

		sum1 = 0;
		for (int j = i; j < N; ++j)	{

			sum1 += arrary[j];

			if (sum2 < sum1){
				sum2 = sum1;
				flag1 = i;
				flag2 = j;
			}			
		}
	}

	cout << sum2 <<" "<< flag1 + 1 <<" " <<flag2 + 1 << endl;;

}


int main(int argc, char const *argv[]){

	int T;  
	int N;

	cin >> T;

	for  (int i = 1; i <= T; ++i){
		
	 	cin >> N;
		
		for (int j = 0; j < N ; ++j){
			
			cin >> arrary[j];
		}


		cout<< "Case "<<i <<":" <<endl;

		output(N);

		if (i == T)
			break;

		cout<<endl;
	}

}*/





// 无回溯法，只要前面的小于0就舍去


#include<iostream>
#include<cstring>
#include<malloc.h>
#include <cstdio>
using namespace std;


int main(){
	int T, N;
	int t, i;
	int a[100001];
	scanf("%d", &T);
	for(t = 0; t < T; t++){
		scanf("%d", &N);
		for(i = 0; i < N; i++)
			scanf("%d", &a[i]);
		int maxSum = a[0];
		int sum = 0, l=0, r=0;
		int tmpL = 0;
		for(i = 0; i < N; i++){
			sum += a[i];
			if(sum > maxSum){
				maxSum = sum;
				l = tmpL;
				r = i;
			}
			if(sum < 0){
				sum = 0;
				tmpL = i+1;
			}
		}
		printf("Case %d:\n", t+1);
		printf("%d %d %d\n", maxSum, l+1, r+1);
		if(t < T-1)
			printf("\n");
	}


	return 0;
}