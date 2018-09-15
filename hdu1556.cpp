#include<bits/stdc++.h>
#define maxn 111111
using namespace std;
int n;
int c[maxn];
int b[maxn];
int lowbit(int x) {
    return x&-x;
}
/**区间修改单点询问**/
/**
add(l-1,-num);add(r,num);
sum(x);
每次修改闭区间lr的值，询问x节点的值
**/
 
void add(int k,int num) {
    while(k) {
        b[k]+=num;
        k-=lowbit(k);
    }
}
int sum(int k) {
    int ans=0;
    while(k<=n) {
        ans+=b[k];
        k+=lowbit(k);
    }
    return ans;
}
int main(){
     while(scanf("%d",&n)&&(n!=0)) {
        memset(b,0,sizeof b);
        int x,y;
        for(int i=1;i<=n;i++) {
            /*scanf("%d%d",&x,&y);
            add(x-1,-1);*/
            add(i,1);
        }
        for(int i=1;i<n;i++) {
            printf("sum %d: %d ",i,sum(i));
        }
        // printf("%d\n",sum(n));
     } 

    return 0;
}
