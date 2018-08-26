#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
char x[maxn];
int kmpnext[maxn];
int len;
int res[maxn];
void pre_kmp(char x[],int m,int kmpnext[]){
    int i,j;
    j=kmpnext[0]=-1;
    i=0;
    while(i<=m){
        if(j==-1||x[i]==x[j]){
            kmpnext[++i]=++j;
        }
        else{
            j=kmpnext[j];
        }
    }
    return;
}
int main(){
    cin>>x;
    len=(int)strlen(x);
    pre_kmp(x,len,kmpnext);
    for(int i=len;i>=1;i--){
        res[i]++;
        res[kmpnext[i]]+=res[i];
    }
    ll ans=0;
    for(ll i=1;i<=len;i++)
        ans=max(ans,res[i]*i);
    cout<<ans<<endl;
    return 0;
}