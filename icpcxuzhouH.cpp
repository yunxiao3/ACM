#include<iostream>
#include<cstdio>
#define INF 99999999
using namespace std;
const int maxn = 100000+10;
typedef long long LL; 
struct node
{
    LL val;
    LL len;
    LL lazy;
    LL l,r;
}tree[maxn*4], tree1[maxn*4];
LL arr[maxn];
LL n,m;

void build(LL root,LL l,LL r)  //建树 
{
    LL mid;
    tree[root].lazy=0;
    tree[root].l=l;tree[root].r=r;
    tree[root].len=r-l+1;

    tree1[root].lazy=0;
    tree1[root].l=l;tree1[root].r=r;
    tree1[root].len=r-l+1;
    if (l==r) {
        tree[root].val=arr[l]*(n - l + 1);
        tree1[root].val=arr[l];
    }
    else
    {
        mid=(l+r)/2;
        build(root*2,l,mid);
        build(root*2+1,mid+1,r);
        tree[root].val=tree[root*2].val+tree[root*2+1].val;
        tree1[root].val=tree1[root*2].val+tree1[root*2+1].val;
    }
}
void pushdown(LL root)  //向下传递lazy标记 
{
    if (tree[root].lazy)
    {
        tree[root*2].lazy+=tree[root].lazy;
        tree[root*2+1].lazy+=tree[root].lazy;
        tree[root*2].val+=tree[root*2].len*tree[root].lazy;
        tree[root*2+1].val+=tree[root*2+1].len*tree[root].lazy;
        tree[root].lazy=0; 
    }
}
void add(LL root,LL id,LL addval)  //单点更新 
{
    LL mid;
    if (tree[root].l==tree[root].r)
    {
        tree[root].val=addval * (n - id + 1);
        tree1[root].val=addval;
        return;
    }
    else
    {
        mid=(tree[root].l+tree[root].r)/2;
        if (id<=mid) add(root*2,id,addval);
        else add(root*2+1,id,addval);
        tree[root].val=tree[root*2].val+tree[root*2+1].val;
        tree1[root].val=tree1[root*2].val+tree1[root*2+1].val;
    }
}

LL query(LL root,LL l,LL r)  //计算区间和 
{
    if(r < l)
      return 0;
    LL mid;
    if (tree[root].l>=l&&tree[root].r<=r)
        return tree[root].val;
    if (tree[root].l>r||tree[root].r<l)
        return 0;
    if (tree[root].lazy) pushdown(root);
    return query(root*2,l,r)+query(root*2+1,l,r);
}

void pushdown1(LL root)  //向下传递lazy标记 
{
    if (tree1[root].lazy)
    {
        tree1[root*2].lazy+=tree1[root].lazy;
        tree1[root*2+1].lazy+=tree1[root].lazy;
        tree1[root*2].val+=tree1[root*2].len*tree1[root].lazy;
        tree1[root*2+1].val+=tree1[root*2+1].len*tree1[root].lazy;
        tree1[root].lazy=0; 
    }
}

LL query1(LL root,LL l,LL r)  //计算区间和 
{ 
    if(r < l)
      return 0;
    LL mid;
    if (tree1[root].l>=l&&tree1[root].r<=r)
        return tree1[root].val;
    if (tree1[root].l>r||tree1[root].r<l)
        return 0;
    if (tree1[root].lazy) pushdown1(root);
    return query1(root*2,l,r)+query1(root*2+1,l,r);
}

int main()
{
    LL i,x,y,z,k;
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    build(1,1,n);

    for (i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&k);
        if (x==2)   
            add(1,y,k);
        else {
          LL ans = query(1,y,n) - query(1,k+1,n)  - query1(1,y,k) * (n - k);      
              printf("%lld\n",ans);
        }
    }
}