#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int bit[5050]={0},n,a[5050];
inline LL min(LL a,LL b){
    return a<b?a:b;
}
inline int lb(int x){
    return x&(-x);
}
inline LL q(int x){
    LL ans=0;
    while(x){
        ans+=bit[x];
        x-=lb(x);
    }
    return ans;
}
inline int c(int x){
    while(x<=n){
        bit[x]++;
        x+=lb(x);
    }
    return 0;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(bit,0,sizeof(bit));
        LL ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]++;
            ans+=q(n)-q(a[i]);
            c(a[i]);
        }
        LL mn=ans;
        mn=min(mn,ans);
        for(int i=1;i<=n;i++){
            ans+=n-a[i]-(a[i]-1);
            mn=min(mn,ans);
        }
        printf("%lld\n",mn);
    }
    
    return 0;
}