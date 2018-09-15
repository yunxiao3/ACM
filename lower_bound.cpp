#include <bits/stdc++.h>
using namespace std;


priority_queue<pair<int,int> > p;
int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        vector<int>vec1, vec2;
        int x,y;
        while(n--) {
            scanf("%d%d", &x, &y);
            vec1.push_back(x);
            vec2.push_back(y);
        }
        cout<<gao(vec1) + gao(vec2)<<endl;
    }
}