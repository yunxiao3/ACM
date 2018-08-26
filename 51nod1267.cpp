#include<cstdio>
#define maxn 500010
int n,m,s;
int a,b;
int d[maxn],q[maxn],f[maxn][32];
int h[maxn],hs;
struct edge{int s,n;}e[maxn<<1];
void dfs(int k,int deep){
    d[k]=deep,q[deep]=k;
    int nd=deep+1;
    for(int i=h[k];i;i=e[i].n)
    if(!d[e[i].s]){
        for(int j=1,k=0;nd>j;j*=2,k++) f[e[i].s][k]=q[nd-j];
        dfs(e[i].s,nd);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        e[++hs]=(edge){b,h[a]},h[a]=hs;
        e[++hs]=(edge){a,h[b]},h[b]=hs;
    }
    dfs(s,1);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        while(a!=b){
            if(d[a]==d[b]) for(int j=0;;j++) if(f[a][j+1]==f[b][j+1]){a=f[a][j],b=f[b][j];break;}
            if(d[a]>d[b]) for(int j=0;;j++) if(d[f[a][j+1]]<d[b]){a=f[a][j];break;}
            if(d[a]<d[b]) for(int j=0;;j++) if(d[f[b][j+1]]<d[a]){b=f[b][j];break;}
        }
        printf("%d\n",a);
    }
    return 0;
}