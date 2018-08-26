
#include<cstring>
#include<iostream>
using namespace std;

#define MAXN 111
#define mod(x) ((x) % MOD)
#define MOD 9973
#define LL long long

int n;

struct mat{
    int m[MAXN][MAXN];
} unit; 

mat operator * (mat a, mat &b){
    mat ret;
    memset(ret.m, 0, sizeof(ret.m));

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            if (a.m[i][k]){
                for (int j = 0; j < n; j++){
                    ret.m[i][j] = mod(ret.m[i][j] + (LL)a.m[i][k] * b.m[k][j]);
                }
            }
        }
    }
    return ret;
}

void init_unit(){
    for (int i = 0; i < MAXN; i++){
        unit.m[i][i] = 1;
    }
    return ;
}

mat pow_mat(mat a, LL n){
    mat ret = unit;
    while (n){
        if (n & 1){
            ret = ret * a;
        }
        n >>= 1;
        a = a * a;
    }
    return ret;
}

int main(){
    LL x;
    init_unit();

    int t;
    cin >> t;

    while (t--){
        cin >> n >> x;
        mat a;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a.m[i][j];
            }
        }
        a = pow_mat(a, x); 

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += a.m[i][i]; 
            sum = mod(sum);
        cout << sum << endl;
    }

    
    return 0;
}