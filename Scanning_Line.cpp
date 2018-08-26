#include <iostream>
#include <algorithm>
#include <stdio.h>
#define lson root<<1
#define rson root<<1|1
using namespace std;
const int maxn = 1e6;
struct Line{
	int lx, rx, h;
	int val;
	Line(){};
	Line(int l , int r, int y, int v){
		lx = l; rx = r;
		h = y; val = v;
	}
	bool operator < (const Line a){
		return a.h < h;
	} 
}line[maxn<<1];

int X[maxn];

struct Tree{
	int l, r;
	int cover;
	int len;
	int mid(){
		return (l + r) >> 1;
	}
}tree[maxn<<3];


void build(int root, int l, int r){
	tree[root].l = l;
	tree[root].r = r;
	tree[root].cover = 0;
	tree[root].len = 0;
	if(l == r)
		return;
	build(lson,l,tree[root].mid());
	
}









int main(int argc, char const *argv[]){
	
	int n = 0,count = 0;
	int x1,y1,x2,y2;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		line[i<<1] = Line(x1,x2,y1,1);
		line[i<<1|1] = Line(x1,x2,y1,-1);
		X[count++] = x1;
		X[count++] = x2;
	}	
	sort(X,X+count);
	sort(line,line+n*2);
	build(1,0)
	return 0;
}