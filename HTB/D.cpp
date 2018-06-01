	#include <iostream>
	#include<vector>
	#include<algorithm>
	#include<cstring>
	#include<cctype>
	using namespace std;

	int main(int argc, char const *argv[]){
		int T; 
		while(cin >> T){


			for (int i = 0; i < T; ++i){


				char str[100000];
				char c;
				int l, r;
				cin >> str >> c;

				int len = strlen(str);

				for (int i = 0; i < len; ++i)
					str[i] = tolower(str[i]);
				
				c = tolower(c);


				for (int i = 0; i < len; ++i){
					l = r = 0;
					if(str[i] == c)
						cout << 0 << " ";
					else{

						while(true){
							if (i - l >= 0 && str[i - l] == c){
								cout << l << " ";
								break;
							}
							if (i + r < len && str[i + r] == c){
								cout << r << " ";
								break;
							}
								l ++;
								r ++;
						}

					}
					
				}


				cout << endl;


			}
		}
		return 0;
	}