#include<iostream>
#include <cstdio>
#include<algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
 
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
 
const int maxn = 1e5 + 7;
const ll mod = 1e9 + 7;
map<int,int> vis;
 
int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int> > qu;
    while(!qu.empty()) qu.pop();
    ll ans = 0, cnt = 0;
    vis.clear();
    
    for(int i = 1; i <= n; ++i) {
      int x; scanf("%d", &x);
      if(qu.empty() || qu.top() >= x) {
        qu.push(x);
      }
      else {
        cnt++;
        int t = qu.top(); qu.pop();
        ans += (x-t);
        if(vis[t] > 0) {
          cnt--;
          vis[t]--;
        }
        qu.push(x); qu.push(x);
        vis[x]++;
      }
    }
    printf("%lld %lld\n", ans, cnt*2);
  }
 
  return 0;
}
