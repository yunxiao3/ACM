#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int mod = 10007;
const int maxn = 100;
ll T,n,m;
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat &a, mat &b) {
    mat c(a.size(), vec(a[0].size()));
    for(int i = 0; i < a.size(); i++) {
        for(int k = 0; k < b.size(); k++) {
            for(int j = 0; j < b[0].size(); j++) {
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod;
            }
        }
    }
    return c;
}
mat pow(mat a, ll n) {
    mat b(a.size(), vec(a[0].size()));
    for(int i = 0; i < a.size(); i++) {
        b[i][i] = 1;
    }
    while(n > 0) {
        if(n & 1) b = mul(b, a);
        a = mul(a, a);
        n >>= 1;
    }
    return b;
}
int main() {
    scanf("%d",&T);
    mat a(3, vec(3));
    while(T--) {
        scanf("%lld",&n);
        a[0][0] = 2; a[0][1] = 1; a[0][2] = 0;
        a[1][0] = 2; a[1][1] = 2; a[1][2] = 2;
        a[2][0] = 0; a[2][1] = 1; a[2][2] = 2;
        a = pow(a, n);
        printf("%d\n",a[0][0]);
    }
    return 0;
}
