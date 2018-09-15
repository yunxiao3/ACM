#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5;
LL a[maxn],b[maxn];
int main(int argc, char const *argv[]){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d%d",&m,&n);
        for (int i = 0; i < n; ++i)
            scanf("%lld",a+i);
        sort(a,a+n);
        for (int k = 1; k < m; ++k){
                for (int i = 0; i < n; ++i)
                    scanf("%lld",b+i);
                sort(b,b+n);
                LL temp;
                priority_queue< LL,vector<LL>,less<LL> > p;
                for (int i = 0; i < n; ++i){
                    p.push(a[i]+b[0]);
                }
                for (int i = 0; i < n; ++i)
                    for(int j = 1; j < n; ++j){
                        temp = a[i]+b[j];
                        if(temp < p.top())
                            p.push(temp), p.pop();
                        else
                            break;
                    }   
                for (int i = n - 1; i >= 0; --i){
                    a[i] = p.top();
                    p.pop();
                }
        }
        for (int i = 0; i < n; ++i)
            printf("%lld ",a[i]);
        printf("\n");
    }
    return 0;
}