#include<iostream>
#include<cstring>
using namespace std;

char str[1500];
		
char buffer[3];
int ans[1000];
int flag;


int main(int argc, char const *argv[]){

	int N;
	cin >> N;
	cin.getline(buffer,3);
	

	for (int i = 0; i < N; ++i){


		cin.getline(str,1500);

		int mw = strlen(str);
		while(str[mw - 1] == ' '){
			str[mw - 1] = '\0';
			mw --;
		}
		// cout << "len2 "<< strlen(str) << endl;



		int pre = 0, pos = 0; 

		while(str[pre + 1] != '\0'  && pre + 1 <= strlen(str) ){

			while(str[pre] == ' ')
				pre++;
			
			pos = pre;

			while(str[pos + 1] != ' ' && str[pos + 1] != '\0')
				pos ++;

			int temp = 0;
			int sum = 0;
	
			while(pos >= pre){

				// cout << "pos " << pos << " pre  " << pre << endl;
				// cout << str[pre] <<endl;
				temp = str[pre] - '0';
				sum += temp;
				sum *= 10;
				pre++;
			}

			sum /= 10;

			flag = sum / 1000;

			// cout << "sum :"<< sum << endl;

			// cout<< "pre" << pre <<endl;
			// cout << sum << endl;
		

			ans[sum % 1000]++;

		}


	}


	int j = 0;

	while(ans[j] == 0){
		j ++;
	}

	int m , n;

	for (int i = j; i <  1000; ++i){
		if (ans[i - 1] != 0 && ans[i] == 0 && ans[i + 1] != 0)
			m = i  + flag * 1000;
		if (ans[i] == 2 )
			n = i + flag * 1000;
	}



	cout << m << " " << n << endl;


	
	return 0;
}