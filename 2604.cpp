#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
 
class Mat
{
public:
    __int64 mat[10][10];
};
 
int n=4;     //维度,即矩阵A的行数
int MOD;//好多问题要求给出取余之后的数字
Mat E;
int f[5]={0,2,4,6,9};
void initE()
{
    for(int i=0;i<10;i++)
        E.mat[i][i]=1;
}
 
Mat operator*(Mat a,Mat b)
{
    int i,j,k;
    Mat c;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            c.mat[i][j] = 0;
                for (k=0;k<n;k++)
                    c.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
                c.mat[i][j]%=MOD;
        }
    }
    return c;
}
 
Mat operator+(Mat a,Mat b)
{
    Mat c;
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            c.mat[i][j] = (a.mat[i][j]+b.mat[i][j])%MOD;
    }
    return c;
}
 
Mat operator^(Mat a,int x)  
{  
     Mat p = E,q = a;  
     while (x>=1)  
     {  
         if(x%2==1)  
             p = p*q;  
         x/=2;  
         q = q*q;  
     }  
     return p;  
}
Mat solve(Mat a,int p)  
 {  
     if(p==1)  
         return a;
     else if(p&1)  
         return (a^p)+solve(a,p-1);  
     else 
         return ((a^(p>>1))+E)*solve(a,p>>1);  
 }  
  
  
 int main()
 {
    int length,mod;
    while(cin>>length>>MOD)
    {
        initE();
        Mat a;
        memset(a.mat,0,sizeof(a.mat));
        a.mat[0][0]=a.mat[0][2]=a.mat[0][3]=a.mat[1][0]=a.mat[2][1]=a.mat[3][2]=1;
          
        if(length<=4)
        {
            cout<<f[length]%MOD<<endl;
            continue;
        }
        Mat x;
         
        x=a^(length-4);
         
        int ans=0;
         
        ans=(x.mat[0][0]*9+x.mat[0][1]*6+x.mat[0][2]*4+x.mat[0][3]*2);
        cout<<ans%MOD<<endl;
    }
    return 0;
 }
