#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<cstdlib>
#include<cmath>
#define PI 2*asin(1.0)
#define LL long long
#define pb push_back
#define pa pair<int,int>
#define clr(a,b) memset(a,b,sizeof(a))
#define lson lr<<1,l,mid
#define rson lr<<1|1,mid+1,r
#define bug(x) printf("%d++++++++++++++++++++%d\n",x,x)
#define key_value ch[ch[root][1]][0]
const int  MOD = 1000000007;
const int N = 2e5 + 15;
const int maxn = 100+ 14;
const int letter = 130;
const int INF = 1e9;
const double pi=acos(-1.0);
const double eps=1e-8;
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,q,pre[N],a[N],sum[N*36],ls[N*36],rs[N*36],root[N];
int siz,ps[N];
void insert(int x,int &y,int l,int r,int d,int v){
    y=++siz;
    ls[y]=ls[x],rs[y]=rs[x],sum[y]=sum[x]+v;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(d<=mid) insert(ls[x],ls[y],l,mid,d,v);
    else insert(rs[x],rs[y],mid+1,r,d,v);
}
int query(int x,int l,int r,int ll,int rr){
    if(ll<=l&&r<=rr) return sum[x];
    int mid=(l+r)>>1;
    int ans=0;
    int m = ll + rr >> 1;
/*    if (m > pos){
        return p[p[c].r ].sum + query(pos,p[c].l,l,m);
    }
    else return query(pos,p[c].r,m+1,r);*/
    if(ll<=mid) ans+=query(ls[x],l,mid,ll,rr);
    if(rr>mid)  ans+=query(rs[x],mid+1,r,ll,rr);
    return ans;
}


int find_k(int x,int l,int r,int k){
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(sum[ls[x]]>=k) return find_k(ls[x],l,mid,k);
    else return find_k(rs[x],mid+1,r,k-sum[ls[x]]);
}


int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        clr(pre,0),siz=0;
        clr(root,0);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        for(int i=n;i;i--){
            insert(root[i+1],root[i],1,n,i,1);
            if(pre[a[i]]) insert(root[i],root[i],1,n,pre[a[i]],-1);
            pre[a[i]]=i;
        }
        ps[0]=0;
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            l=(l+ps[i-1])%n+1,r=(r+ps[i-1])%n+1;
            if(l>r) swap(l,r);
            int mid=query(root[l],1,n,l,r);
            mid=(mid+1)/2;
            ps[i]=find_k(root[l],1,n,mid);
        }
        printf("Case #%d:",++cas);
        for(int i=1;i<=q;i++) printf(" %d",ps[i]);
        puts("");
    }
    return 0;
}