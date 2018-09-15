#include <bits/stdc++.h>
using namespace std;

long long gao(vector<int> vec) {
    int sz = vec.size();
    set<int>st;
    long long ans = 0;
    for (int i = sz-1; i >= 0; i--) {//倒着访问
        set<int>::iterator it = st.lower_bound(vec[i]);
        if (it == st.begin()) {//如果当前的坐标比所有的小，说明另一个肯定比他们大，所以加全部，图二
            ans += vec[i];
        } else {
            it--;
            ans += vec[i] - *it;//图一
        }
        st.insert(vec[i]);
    }
    return ans;
}
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