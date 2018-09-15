#include<iostream>
using namespace std;
int dp[250025];
int v[100],num[100];
int max( int a,int b ) 
{ 
    return a > b ? a : b; 
} 
int main()
{
    int i,j,n,sum,cnt,k;
    while(scanf("%d",&n),n>0)
    {
      cnt=0;
      for(i=0;i<n;i++){ scanf("%d%d",&v[i],&num[i]);cnt+=v[i]*num[i];}
      memset(dp,0,sizeof(dp));
      sum=cnt/2;
      for(i=0;i<n;i++)
        for(j=0;j<num[i];j++)
           for(k=sum;k>=v[i];k-=v[i])                 
             dp[k]=max(dp[k],dp[k-v[i]]+v[i]);
      if(cnt-dp[sum]>dp[sum])
       printf("%d %d\n",cnt-dp[sum],dp[sum]);
       else printf("%d %d\n",dp[sum],cnt-dp[sum]);
    }
    return 0;
}
             
      

