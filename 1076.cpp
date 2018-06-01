
#include<iostream>

#include<algorithm>//sort头文件

using namespace std; 

int main()

{

int a[100000],n,i,j,t;

cin>>n;

for(i=0;i<n;i++)

cin>>a[i];

std::sort(a,a+n);//对a[0]至a[n-1]排序

for(i=0;i<=n-1;i++)

cout<<a[i]<<" ";

return 0;

}
