
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
 
int main(int argc, char** argv) {
	priority_queue<int>q;//大根堆 
	int n;
	scanf("%d",&n);
	int x;
	ll z=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x);//读入卖出收益 
		q.push(-x);
		q.push(-x);
		ll tmp=x+q.top();//净利润=卖出收益-买入成本(最小成本） -10 -5 -4 -4 -5 -7 -6 -2 -2
		//printf("%lld ",tmp); //每天的净利润 
		cout<< x <<" "<< q.top() << endl;
		z+=tmp;
		q.pop(); 
	} 
	printf("\n%lld\n",z);
	return 0;
}