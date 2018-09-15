#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int INF=0x33333333;
const int N=50001;
struct node{
    int x,y,ls,rs,ms,lazy;
};
node tree[N<<2];
int n,m;

void update(int bh){
    int lc=bh<<1;
    int rc=bh<<1|1;
    if (tree[bh].x!=tree[bh].y){ 
        if (tree[lc].ms==tree[lc].y-tree[lc].x+1) //都为空
            tree[bh].ls=tree[lc].ms+tree[rc].ls; 
        else tree[bh].ls=tree[lc].ls;
        if (tree[rc].ms==tree[rc].y-tree[rc].x+1)  //==
            tree[bh].rs=tree[rc].ms+tree[lc].rs;
        else tree[bh].rs=tree[rc].rs;
        tree[bh].ms=max(tree[lc].ms,tree[rc].ms);
        tree[bh].ms=max(tree[bh].ms,tree[lc].rs+tree[rc].ls);
    }
}

void push(int bh){
    int lc=bh<<1;
    int rc=bh<<1|1;
    if (tree[bh].lazy!=0&&tree[bh].x!=tree[bh].y){
        if (tree[bh].lazy==1){
            tree[lc].ls=tree[lc].rs=tree[lc].ms=0;
            tree[rc].ls=tree[rc].rs=tree[rc].ms=0;
        }
        else{
            tree[lc].ls=tree[lc].rs=tree[lc].ms=tree[lc].y-tree[lc].x+1;
            tree[rc].ls=tree[rc].rs=tree[rc].ms=tree[rc].y-tree[rc].x+1;
        }
        tree[lc].lazy=tree[rc].lazy=tree[bh].lazy;
        tree[bh].lazy=0;
    }
}

void build(int bh,int l,int r){
    tree[bh].x=l;
    tree[bh].y=r;
    if (l==r){
        tree[bh].ls=tree[bh].rs=tree[bh].ms=1;
        return;
    }
    int mid=(l+r)>>1;
    build(bh<<1,l,mid);
    build(bh<<1|1,mid+1,r);
    update(bh);
}

void add(int bh,int l,int r){
    push(bh);
    if (tree[bh].x>=l&&tree[bh].y<=r) {
        tree[bh].ls=tree[bh].rs=tree[bh].ms=0;  //计算0序列长度 
        tree[bh].lazy=1;
        return;  //
    }
    int mid=(tree[bh].x+tree[bh].y)>>1;
    if (l<=mid) add(bh<<1,l,r);
    if (r>mid) add(bh<<1|1,l,r);
    update(bh);  //
}

void jian(int bh,int l,int r){
    push(bh);
    if (tree[bh].x>=l&&tree[bh].y<=r) {
        tree[bh].ls=tree[bh].rs=tree[bh].ms=tree[bh].y-tree[bh].x+1;
        tree[bh].lazy=-1;
        return;  //
    }
    int mid=(tree[bh].x+tree[bh].y)>>1;
    if (l<=mid) jian(bh<<1,l,r);
    if (r>mid) jian(bh<<1|1,l,r);
    update(bh);  //
}

int doit(int bh,int len){
    push(bh);
    if (tree[bh].x==tree[bh].y) return tree[bh].x;  //==
    int lc=bh<<1;
    int rc=bh<<1|1;
    push(lc); push(rc);
    if (tree[lc].ms>=len) doit(lc,len);
    if (tree[lc].rs+tree[rc].ls>=len) return tree[lc].y-tree[lc].rs+1;  //位置
    else if (tree[rc].ms>=len) doit(rc,len);  //else 
}

int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for (int i=1;i<=m;i++){
        int opt,u,w;
        scanf("%d",&opt);
        if (opt==1){
            scanf("%d",&u);
            if (tree[1].ms<u) printf("0\n");
            else {
                int t=doit(1,u);
                printf("%d\n",t);  //
                add(1,t,t+u-1);
            }
        }
        else{
            scanf("%d%d",&u,&w);
            jian(1,u,u+w-1);
        }
    }
    return 0;
} 