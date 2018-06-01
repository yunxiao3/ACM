
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f 
int a[10][10];
int dx[5] = {0,1,0,-1,1};
int dy[5] = {1,0,-1,0,-1};
bool isv[10][10];
int M,N,SUM;
int Min = INF ;
bool judge(int x,int y,int num)
{
    if( x<1 || y<1 || x>N || y>M )    //越界 
        return 1;
    if( isv[x][y] )    //访问过 
        return 1;
    if( num + a[x][y] > SUM/2 )    //走这一步超过了和的1半 
        return 1;
    return 0;
}
bool judgeNotSeperate(int count){//用来判断是否区间被分开了
  //  Print(); 
	int temcount=0;
	for(int i=1;i<=N;i++)
	  for(int j=1;j<=M;j++){
	  	if(isv[i][j]==false){//当该位置未被访问到，有可能会出现间断 
	  	   temcount++;
		   if( (i+1<=N&&isv[i+1][j]==0)||(i-1>=0&&isv[i-1][j]==0)||(j+1<=M&&isv[i][j+1]==0)||(j-1>=0&&isv[i][j-1]==0) )//如果周围有同样没有被访问到的说明在该点没有出现间断 
		       continue;
		   else
		     return  count-temcount==0 ? true:false;//若为最后一点，同样返回true 
	  	}
	  }
	  return true;
} 
int dfs(int x,int y,int num,int count)//num计算路径和，count为路径长度计数器 
{
    if(num==SUM/2){
      if(Min>count&&judgeNotSeperate(M*N-count))//judgeNotSeperate(M*N-count)判断是否切割为多部分 ，这道题数据比较小，没有必要剪枝，但是稍微大点就应该在深搜的时候剪枝了。。。
         Min=count;
       return 0;
	}
    for(int i=0;i<5;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( judge(nx,ny,num) )    //判断 
            continue;
                                    //下一步可以走
        isv[nx][ny] = true;			
        dfs(nx,ny,num+a[nx][ny],count+1);
        isv[nx][ny] = false;   //还原 
    }
    return 0; 
}
int main()
{
    while(cin>>M>>N){
    	Min=INF;//一定注意初始化//不过水水的蓝桥杯上每次只有一组测试数据，随意循环输入多组测试数据只是自己方便，测试网站上每组输入都会有^EOF的（当然while（1）是肯定不行的））
        SUM = 0;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                cin>>a[i][j];
                SUM += a[i][j];
            }
        if( SUM%2 ){    //和是奇数一定不可以 
            cout<<0<<endl;
        }
        else{    //和是偶数继续判断
            memset(isv,0,sizeof(isv));
            isv[1][1] = true;
			dfs(1,1,a[1][1],1);
			if(Min==INF)
			  cout<<0<<endl;
            else
			  cout<<Min<<endl;
        }
    }
    return 0;
}