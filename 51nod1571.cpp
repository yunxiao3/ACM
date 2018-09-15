#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;
typedef long long ll;
template <class T>
bool read(T &x){
    char c;
    bool op = 0;
    while(c = getchar(), c < '0' || c > '9')
        if(c == '-') op = 1;
        else if(c == EOF) return 0;
    x = c - '0';
    while(c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    if(op) x = -x;
    return 1;
}
template <class T>
void write(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 500005;
int n, m, q, a[N], s[N], last[N], left[N], data[4*N], ans[N];
struct Query {
    int id, l, r;
    bool operator < (const Query &b) const{
        return r < b.r;
    }
} Q[N];

void build(int k, int l, int r){
    if(l == r) return (void)(data[k] = INF);
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    data[k] = INF;
}

void change(int k, int l, int r, int p, int x){
    if(l == r) return (void)(data[k] = x);
    int mid = (l + r) >> 1;
    if(p <= mid) change(k << 1, l, mid, p, x);
    else change(k << 1 | 1, mid + 1, r, p, x);
    data[k] = min(data[k << 1], data[k << 1 | 1]);
}

int query(int k, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r) return data[k];
    int mid = (l + r) >> 1, ret = INF;
    if(ql <= mid) ret = min(ret, query(k << 1, l, mid, ql, qr));
    if(qr > mid) ret = min(ret, query(k << 1 | 1, mid + 1, r, ql, qr));
    return ret;
}

int main(){

    read(n), read(q);
    for(int i = 1; i <= n; i++)
        read(a[i]), s[i] = a[i];
    sort(s + 1, s + n + 1);
    int m = unique(s + 1, s + n + 1) - s - 1;
    
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(s + 1, s + m + 1, a[i]) - s;
        left[i] = last[a[i]];
        last[a[i]] = i;
    }

    build(1, 1, n);
    
    for(int i = 1; i <= q; i++)
        Q[i].id = i, read(Q[i].l), read(Q[i].r);
    sort(Q + 1, Q + q + 1);

    for(int i = 1, j = 1; i <= n && j <= q; i++){
    
        if(left[i]) change(1, 1, n, left[i], i - left[i]);
    
        while(j <= q && i == Q[j].r){
    
            ans[Q[j].id] = query(1, 1, n, Q[j].l, Q[j].r);
            j++;
        }
    }
    for(int i = 1; i <= q; i++)
        write(ans[i] < INF ? ans[i] : -1), enter;
    return 0;
}
