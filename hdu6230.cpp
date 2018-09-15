/*
* @Author: wchhlbt
* @Last Modified time: 2017-11-12
*/
 
#include <bits/stdc++.h>
 
#define inf 0x3f3f3f3f
#define pb push_back
#define AA first
#define BB second
#define ONES(x) __builtin_popcount(x)
#define _  << " " <<
using namespace std;
 
typedef pair<int, int> P;
typedef long long ll ;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const double eps =1e-3;
const int mod = 1000000007;
const double PI = acos(-1.0);
inline int read(){ int num;    scanf("%d",&num);   return num;}
const int maxn = 500007;
 
char Ma[maxn*2];
int Mp[maxn*2];
int Manacher(char s[],int len){
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for(int i = 0; i<len; i++){
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for(int i = 0; i<l; i++){
        Mp[i] = mx>i ? min(Mp[2*id-i],mx-i) : 1;
        while(i-Mp[i]>=0 && Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i+Mp[i]>mx){
            mx=i+Mp[i];
            id=i;
        }
    }
    return l;
}
 
char s[maxn];
int p[maxn];
vector<int> g[maxn];
 
//BIT 向下统计 向上修改
int bit[maxn];
int n;
int sum(int i){
    int s = 0;
    while(i>0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
 
void add(int i, int x)//i 不能取 0
{
    while(i<=n){
        bit[i] += x;
        i += i&-i;
    }
}
 
int main(){
    int t = read();
    while(t--){
        //init
        memset(bit,0,sizeof bit);
        for(int i = 0; i<maxn; i++) g[i].clear();
 
        scanf("%s",s);
        int slen = strlen(s);
        int len = Manacher(s,slen);
        int k = 1;
        for(int i = 2; i<len; i+=2){
            p[k] = Mp[i]/2 -1;
            // printf("%d ",p[k]);
            //cout << k _ p[k] _ Mp[i] << endl;
            g[k-p[k]].pb(k);
            k++;
        }
        n = slen;
        ll ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<g[i].size(); j++){
                add(g[i][j],1);
                // printf("%d ",g[i][j]);
            }
            // printf("%d\n",i );
            ans += sum(min(i+p[i],n)) - sum(i);
        }
        cout << ans << endl;
    }
    return 0;
}
