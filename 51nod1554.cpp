#include<stdio.h>
const int N=1e6+2005;
int nxt[N],n,m;
char s[N];
void getnxt(){
    int j=-1,i=0;
    nxt[0]=-1;
    while(i<n){
        if(j==-1||s[i]==s[j])
        nxt[++i]=++j;
        else
        j=nxt[j];
    }
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    getnxt();
    for(int i=1;i<=n;i++){
        int x=i/(i-nxt[i]);
        if(i%(i-nxt[i])){
            if(x/m > x%m)printf("1");
            else printf("0");
        }
        else{
            if(x/m >= x%m)printf("1");
            else printf("0");
        }
    }
    printf("\n");
    return 0;
}
