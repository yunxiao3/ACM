
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

struct node
{
    int lc;
    int rc;
    node(){lc=0;rc=0;}
};
node a[17];
queue<int> q[2];
int w=0;
int h=0;
void bfs()
{
    q[1].push(1);
    int i=1;
    int k=0;
    while(i<=h)
    {
        int tmp=q[i%2].size();
        w=max(w,tmp);
        while(!q[i%2].empty())
        {
        k=q[i%2].front();
        q[i%2].pop();
        if(a[k].lc){q[(i+1)%2].push(a[k].lc);}
        if(a[k].rc){q[(i+1)%2].push(a[k].rc);}
        }
        i++;
    }
}
void build(int n)
{
    for(int i=1;i<=n;i++)
    {
        int x=0,y=0;
        scanf("%d%d",&x,&y);
        a[i].lc=x;
        a[i].rc=y;
    }
}
int post(int i)
{
    if(!a[i].lc && !a[i].rc){return 1;}
    int t=0,j=0;
    if(a[i].lc)
    t=post(a[i].lc);
    if(a[i].rc)
    j= post(a[i].rc);
    return (t<j)?j+1:t+1;
}
int main()
{
    int n=0;
    scanf("%d",&n);
    build(n);
    h=post(1);
    bfs();
    printf("%d %d\n",w,h);
    return 0;
}



