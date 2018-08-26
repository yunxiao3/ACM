#include<bits/stdc++.h>
using namespace std;
int n,m;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	while(scanf("%d %d",&n,&m)!=EOF)printf("%d\n",n*m/gcd(n,m));
}