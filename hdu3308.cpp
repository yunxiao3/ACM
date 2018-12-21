#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 200000+100;
struct node{
	int l, r;
	int lv,rv;
	int llen, rlen, mlen;
}c[maxn*4];
int a[maxn];
void push_up(int root){
	c[root].lv = c[root<<1].lv;
	c[root].rv = c[root<<1|1].rv;
	c[root].llen = c[root<<1].llen;
	c[root].rlen = c[root<<1|1].rlen;
	c[root].mlen = max(c[root<<1].mlen,c[root<<1|1].mlen);
	if(c[root<<1].rv < c[root<<1|1].lv){
		c[root].mlen = max(c[root<<1].rlen + c[root<<1|1].llen, c[root].mlen);
		if(c[root<<1].llen == (c[root<<1].r - c[root<<1].l + 1))
			c[root].llen += c[root<<1|1].llen;
		if(c[root<<1|1].rlen == (c[root<<1|1].r - c[root<<1|1].l + 1))
			c[root].rlen += c[root<<1].rlen;
	}
	// c[root].m = max(c[root].mlen,max(c[root].m,c[root].m));
}

void build(int root, int l, int r){
	c[root].l = l;
	c[root].r = r;
	if(l == r){
		c[root].lv = a[l];
		c[root].rv = a[l];
		c[root].llen = 1;
		c[root].rlen = 1;
		c[root].mlen = 1;
		return ;
	}
	int mid = (r+l) >> 1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	push_up(root);
	// c[root].m = max(,c[root<<1|1].m);
}
void update(int root, int pos, int v){
	if(c[root].l == c[root].r){
		c[root].lv = v;
		c[root].rv = v;
		return;
	}
	int mid = (c[root].l + c[root].r) >> 1;
	if(mid >= pos)
		update(root<<1,pos,v);
	else
		update(root<<1|1,pos,v);
	push_up(root);
}
int qurey(int root, int l, int r){
	if(l <= c[root].l && r >= c[root].r)
		return c[root].mlen;
	int mid = (c[root].r + c[root].l) >> 1;
	int Max = 0;
	if(mid >= l)	
		Max = qurey(root << 1, l, r);
	if(mid < r)
			Max = max(Max,qurey(root << 1 | 1, l, r));
		if(c[root<<1].rv < c[root<<1|1].lv)
			Max = max(Max,min(mid-l+1,c[root<<1].rlen) + min(r - mid, c[root<<1|1].llen));
	return Max;
}
int main(int argc, char const *argv[]){
	int n,m,x1,x2;
	char s[2];
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; ++i)
			scanf("%d",a+i);
		build(1,1,n);
		while(m--){
			scanf("%s%d%d",s,&x1,&x2);
			if(s[0] == 'Q') 
				printf("%d\n",qurey(1,x1+1,x2+1));
			else
				update(1,x1+1,x2);
		}
	}
	return 0;
}
	