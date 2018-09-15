#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long LL;
const long long MAXN=100000+100;
long long a[MAXN],sum[MAXN<<2],lazy[MAXN<<2];
//a[]为原序列信息，sum[]模拟线段树维护区间和，lazy[]为懒惰标记
void PushUp(long long rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(long long rt,long long ln,long long rn){//ln表示左子树元素结点个数，rn表示右子树结点个数
    if (lazy[rt]){
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        sum[rt<<1]+=lazy[rt]*ln;
        sum[rt<<1|1]+=lazy[rt]*rn;
       /* lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        sum[rt<<1] = lazy[rt]*ln;
        sum[rt<<1|1] = lazy[rt]*rn;
        */
        lazy[rt]=0;
    }
}

void Build(long long l,long long r,long long rt){
    if (l==r){
        sum[rt]=a[l];
        // sum[rt] = 1;
        return;
    }
    long long mid=(l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}
void Add(long long L,long long C,long long l,long long r,long long rt){
    if (l==r){
        sum[rt]+=C;
        return;
    }
    long long mid=(l+r)>>1;
    PushDown(rt,mid-l+1,r-mid); //若既有点更新又有区间更新，需要这句话
    if (L<=mid)
        Add(L,C,l,mid,rt<<1);
    else
        Add(L,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}
void Update(long long L,long long R,long long C,long long l,long long r,long long rt){
    if (L<=l&&r<=R){
        sum[rt]+=C*(r-l+1);
        lazy[rt]+=C;
        //sum[rt] = C*(r-l+1);
        //lazy[rt] = C;
        // printf("sasa\n");
        return;
    }
    long long mid=(l+r)>>1;
    PushDown(rt,mid-l+1,r-mid);
    if (L<=mid) Update(L,R,C,l,mid,rt<<1);
    if (R>mid) Update(L,R,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}
long long Query(long long L,long long R,long long l,long long r,long long rt)    {
    if (L<=l&&r<=R)
        return sum[rt];
    long long mid=(l+r)>>1;
    PushDown(rt,mid-l+1,r-mid);//若更新只有点更新，不需要这句
    long long ANS=0;
    if (L<=mid) ANS+=Query(L,R,l,mid,rt<<1);
    if (R>mid) ANS+=Query(L,R,mid+1,r,rt<<1|1);
    return ANS;
}

int  main(int argc, char const *argv[]){
    memset(lazy,0,sizeof(lazy));
    long long n;
    scanf("%lld",&n);
    long long m;
    scanf("%lld",&m);
    for (long long i = 1; i <= n; ++i)
        scanf("%lld",a+i);
    // printf("adsdd\n");
    Build(1,n,1);
    long long x,y,z;
    char c;
    for (long long i = 0; i < m; ++i){
        scanf(" %c",&c);
        if(c == 'C'){
             scanf("%lld%lld%lld",&x,&y,&z);
            Update(x,y,z,1,n,1);
        }
        else{
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",Query(x,y,1,n,1));
        }
    }
    
    return 0;
}