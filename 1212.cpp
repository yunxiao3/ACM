#include<bits/stdc++.h>

using namespace std;

template<class T>void read(T &x)

{

 x=0;int f=0;char ch=getchar();

 while(ch<'0'||ch>'9'){ f|=(ch=='-');ch=getchar(); }

 while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar(); }

 x=f? -x:x;

 return;

}

int gcd(int a,int b)

{

 int c;

 while(a%b!=0)

 {

  c=a%b;

  a=b;

  b=c;

 }

 return b;

}

int main()

{

 long long a,b;

 read(a);

 read(b);

 printf("%d",gcd(a,b));

 return 0;

}



