#include <bits/stdc++.h>
using namespace std;

/*本来要判断八个格子，
 *但是由于是从左往右从上往下填的，
 *只要判断左、左上、上、右上
*/
const int dx[]={0,-1,-1,-1};
const int dy[]={-1,-1,0,1};
const int INF=1e9;
bool used[10];
int ans=0;
int a[5][5];
int b;
bool alright(int n,int x,int y)
{
    for (int i=0;i<4;i++) {
        int xx=x+dx[i],yy=y+dy[i];
        if (xx<1||yy<1||xx>3||yy>4) continue;
        if (abs(n-a[xx][yy])==1) return false;
    }
    return true;
}




void dfs(int x,int y)
{
    if (x==3&&y==4) {

        if (b < 10)
{
    

    	for (int i=1;i<=3;i++) {
        for (int j=1;j<=4;j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
    b++;
}
        ans++;
        return;
    }
    for (int i=0;i<=9;i++) {
        if (!used[i]&&alright(i,x,y)) {
            a[x][y]=i;
            used[i]=true;
            if (y==4) dfs(x+1,1);
            else dfs(x,y+1);
            used[i]=false;
            a[x][y]=-INF;
        }
    }
}

int main()
{
    for (int i=1;i<=3;i++) {
        for (int j=1;j<=4;j++) {
            a[i][j]=-INF;
        }
    }
    dfs(1,2);
    printf("%d\n",ans);
	

    return 0;
}