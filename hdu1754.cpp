#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 200000+100;
struct node{
	int l, r, m;
}c[maxn*4];
int a[maxn];

void build(int root, int l, int r){
	c[root].l = l;
	c[root].r = r;
	if(l == r){
		c[root].m = a[l];
		return ;
	}
	int mid = (r+l) >> 1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	c[root].m = max(c[root<<1].m,c[root<<1|1].m);
}
void update(int root, int pos, int v){
	if(c[root].l == c[root].r){
		c[root].m = v;
		return;
	}
	int mid = (c[root].l + c[root].r) >> 1;
	if(mid >= pos)
		update(root<<1,pos,v);
	else
		update(root<<1|1,pos,v);
	c[root].m = max(c[root<<1].m,c[root<<1|1].m);
}
int qurey(int root, int l, int r){
	if(l == c[root].l && r == c[root].r)
		return c[root].m;
	if(r <= c[root<<1].r) return qurey(root << 1,l, r);
	if(c[root<<1|1].l <= l)  return qurey(root << 1 | 1,l, r);
	return max(qurey(root << 1,l, c[root<<1].r),qurey(root << 1|1, c[root<<1|1].l, r));
}
int main(int argc, char const *argv[]){
	int n,m,x1,x2;
	char s[2];
	while(cin >> n >> m){
		for (int i = 1; i <= n; ++i)
			scanf("%d",a+i);
		build(1,1,n);
		while(m--){
			scanf("%s%d%d",s,&x1,&x2);
			if(s[0] == 'Q') 
				printf("%d\n",qurey(1,x1,x2));
			else
				update(1,x1,x2);
		}
	}
	return 0;
}
	
