#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
    int a,b,rs,ls,sum;
}tr[2000010];
int a[100010],b[100010];
int rt[100010],pos,cnt;
void Build(int &node,int a,int b){
    node=++cnt;
    tr[node].a=a;
    tr[node].b=b;
    if(a==b)return;
    int mid=(a+b)>>1;
    Build(tr[node].ls,a,mid);
    Build(tr[node].rs,mid+1,b);
}

void Insert(int pre,int &node){
    node=++cnt;
    tr[node].ls=tr[pre].ls;
    tr[node].rs=tr[pre].rs;
    tr[node].a=tr[pre].a;
    tr[node].b=tr[pre].b;
    tr[node].sum=tr[pre].sum+1;
    if(tr[node].a==tr[node].b)return;
    int mid=(tr[node].a+tr[node].b)>>1;
    if(mid>=pos)Insert(tr[pre].ls,tr[node].ls);
    else Insert(tr[pre].rs,tr[node].rs);
}
int Query(int pre,int node,int k){
    if(tr[node].ls==tr[node].rs)return b[tr[node].a];
    int cmp=tr[tr[node].ls].sum-tr[tr[pre].ls].sum;
    if(cmp>=k)return Query(tr[pre].ls,tr[node].ls,k);
    else return Query(tr[pre].rs,tr[node].rs,k-cmp);
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;b[i]=a[i],i++)
        scanf("%d",&a[i]);
    sort(b+1,b+n+1);
    Build(rt[0],1,n);
    for(int i=1;i<=n;i++){
        pos=lower_bound(b+1,b+n+1,a[i])-b;
        Insert(rt[i-1],rt[i]);
    }    
    int l,r,k;
    for(int i=1;i<=q;i++){
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",Query(rt[l-1],rt[r],k));
    }
    return 0;
}