#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <map>
using namespace std;
const int maxn = 4*1e7 + 100;
const int mod = 1000000007;
typedef long long LL;


string tohex(string s){
	string c="";
	map<char, string> p1;
	p1['0']="0000";//这样转换成2进制感觉方便
	p1['1']="0001";
	p1['2']="0010";
	p1['3']="0011";
	p1['4']="0100";
	p1['5']="0101";
	p1['6']="0110";
	p1['7']="0111";
	p1['8']="1000";
	p1['9']="1001";
	p1['A']="1010";
	p1['B']="1011";
	p1['C']="1100";
	p1['D']="1101";
	p1['E']="1110";
	p1['F']="1111";
	for (int i = 0; i < s.length(); ++i){
		c += p1[s[i]];
	}
	return c;
}

string delet(string s){
	int len = s.length() / 9;
	string c = "";
	for (int i = 0; i < len; ++i){
		int count = 0;
		for (int j = i * 9; j < (i+1) * 9 - 2; j++){
			if(s[j] == '1')
				count ++;
		}
		if(count % 2 == 0 && s[(i+1) * 9 - 1] == '1' || count % 2 == 1 && s[(i+1) * 9 - 1] == '0'  )
			c += s.substr(i * 9,8);
	}
}

int main(int argc, char const *argv[]){
	int t;
	scanf("%d",&t);
	while(t--){
		int m, n;
		scanf("%d%d",&m,&n);
		map <string, char> mp;
		for (int i = 0; i < n; ++i){
			char c;
			string str;
			cin >> c >> str;
			mp[str] = c;
		}
		string a;
		cin >> a;
		for (int i = 0; i < a.length(); ++i){
			if(isalpha(a[i]))
				a[i] = toupper(a[i]);
		}
		a = tohex(a);
		a = delet(a);
		string code = "";
		int count1 = 0;
		for (int i = 0; i < a.length(); i++){
			code += a[i];
			if(mp[code]){
				printf("%c\n",mp[code]);
				code = "";
				count1 ++;
			}
			if(count1 == m)
				break;
		}


	}



	return 0;
}