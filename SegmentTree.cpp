#include <iostream>
using namespace std;
const int maxn = 1e6+100;

int a[maxn];
struct node{
	int l,r,sum;
}c[maxn * 4];


int build(int root, int l, int r){
	if(l == r){
		c[root].sum = a[l]; 
		return 0;
	}
	c[root].l = l;
	c[root].r = r;
	int mid = (r+l)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	c[root].sum = c[root>>1|1].sum + c[root>>1].sum;
}

int main(int argc, char const *argv[]){
    
	return 0;
}
