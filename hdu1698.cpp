#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn=50505;
int n,m,t;
int a[maxn];
char s[10];
int x,y;
struct node{
    int l,r;
    int sum;
    int lazy;
    void update(int v){
        sum+=(r-l+1)*v;
        lazy+=v;
    }
};
node tree[maxn*4];
inline void push_down(int o){
    int lazyval=tree[o].lazy;
    tree[2*o].update(lazyval);
    tree[2*o+1].update(lazyval);
    tree[o].lazy=0;
}
inline void push_up(int o){
    tree[o].sum=tree[o*2].sum+tree[o*2+1].sum;
}
inline void build_tree(int L,int R,int o){
    tree[o].l=L;
    tree[o].r=R;
    tree[o].sum=tree[o].lazy=0;
    if(L==R)tree[o].sum=a[L];
    else{
        int mid =(R+L)/2;
        build_tree(L,mid,o*2);
        build_tree(mid+1,R,o*2+1);
        push_up(o);
    }
}
inline void update(int l,int r,int v,int o){
    int L=tree[o].l;
    int R=tree[o].r;
    if(l<=L&&R<=r)tree[o].update(v);
    else{
        push_down(o);
        int mid = (L+R)>>1;
        if(l<=mid)update(l,r,v,o*2);
        if(mid<r)update(l,r,v,o*2+1);
        push_up(o);
    }
}
inline int query(int l,int r,int o){
    int L=tree[o].l;
    int R=tree[o].r;
    if(l<=L&&r>=R)return tree[o].sum;
    else{
        push_down(o);
        int mid =(L+R)>>1;
        int res=0;
        if(l<=mid)res+=query(l,r,o*2);
        if(r>mid)res+=query(l,r,o*2+1);
        push_up(o);
        return res;
    }
}
int main(){
    int t;
    cin>>t;
    int k=0;
    while(t--){
        k++;
        scanf("%d",&n);
 
        for(int i=1;i<=n;i++){
           scanf("%d",&a[i]);
        }
        build_tree(1,n,1);
        int ok=0;
        while(scanf("%s",s)){
            if(s[0]=='E')break;
            if(s[0]=='Q')
            {
               scanf("%d%d",&x,&y);
                if(ok==0)
                {
                       printf("Case %d:\n",k);
                       ok=1;
                }
                printf("%d\n",query(x,y,1));
            }
            if(s[0]=='A')
            {
                scanf("%d%d",&x,&y);
                update(x,x,y,1);
            }
            if(s[0]=='S')
            {
                scanf("%d%d",&x,&y);
                update(x,x,-y,1);
            }
        }
    }
}
