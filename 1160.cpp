#include<bits/stdc++.h>

using namespace std;

int main(){

    int a[101][101],n = 5,x,y,tot,b,ans=0;

    memset(a,0,sizeof(a));

   cin>>n;

    x = y = n;


    tot = n * n;
    a[n][n] = tot;
    while (tot > 1){

        while(!a[x][y-1] && y > 1){
            a[x][--y] = --tot;
        }

         while(!a[x-1][y] && x > 1){
            a[--x][y] = --tot;
        }
         while(!a[x][y + 1] && y < n){
            a[x][++y] = --tot;
        }
        while(!a[x + 1][y] && x < n){
            a[++x][y] = --tot;
        }


    } 



for (int i = 1, j = n; i <= n ; i++, j--){
    ans += a[i][i] + a[i][j];
}


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
          cout << a[i][j] << " " ;

        cout<<endl;
    }

cout << ans - 1;

    
return 0; 

}

