#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const long long maxn = 1e6 + 100;

int h,w,n;

struct Node{
	int l,r,m;
}node[maxn*4];


void build(int rt, int l, int r){
	node[rt].l = l;
	node[rt].r = r;
	node[rt].m = w;
	int mid = (l+r)>>1;
	if(l==r)
		return;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}


int update(int root, int m){
	if(node[root].m < m)
		return -1;
	if(node[root].l == node[root].r){
		node[root].m -= m;
		return node[root].l;
	}
	int ans = 0;
	if(node[root << 1].m >= m)
		ans = update(root<<1,m);
	else
		ans = update(root<<1|1,m);
	node[root].m = max(node[root<<1].m,node[root<<1|1].m);
	return ans;
}



int main(int argc, char const *argv[]){
	while(scanf("%d%d%d",&h,&w,&n) != EOF){
		build(1,1,min(h,n));
		for (int i = 0, b; i < n; ++i)
			scanf("%d",&b), printf("%d\n",update(1,b));
	}
	return 0;
}