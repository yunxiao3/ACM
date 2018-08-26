#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e6;

struct  node{
	int val;
	int pos;
	bool friend operator < (node x, node y){
		if(x.val == y.val)
			return x.pos < y.pos;
		return x.val < y.val;
	}
}a[maxn];
// :: sync_with_stdio(flase);

int main(int argc, char const *argv[]){
	ios::sync_with_stdio(false);  
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a[i].val;
		a[i].pos = i;
	}
	sort(a,a+n);
	int ans = 0;
	int temp = a[0].pos;
	for (int i = 1; i < n; ++i){
		if(a[i].pos > temp)
			ans = max(ans,a[i].pos - temp);
		else
			temp = a[i].pos;
	}

	cout << ans << endl;

	return 0;
}