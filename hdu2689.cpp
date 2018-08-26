#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000;
int n,c[maxn];

int lowbit(int x){
	return x & (-x);
}

void  update(int i,int x){
	while(i <= n){
		c[i] = c[i] + x;
		i += lowbit(i);
	}
}

int getsum(int i){
	int ans = 0;
	while(i > 0){
		ans += c[i];
		i -= lowbit(i);
	}
	return ans;
}

int main(int argc, char const *argv[]){
	while(cin >> n){
		memset(c,0,sizeof(c));
		int a = 0, sum = 0;
		for (int i = 1; i <= n; ++i){
			scanf("%d",&a);
			update(a,1);
			sum += (i - getsum(a));
			//cout << i << " " << sum << endl;
		}
		printf("%d\n",sum);
	}
	return 0;
}