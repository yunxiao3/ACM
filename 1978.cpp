#include<iostream>

using namespace std;

#define N 46

int main()

{

    int n, a[N];

for(int i=0; i<N; i++)

{

   if(i<2)    a[i]=1;

   else    a[i]=a[i-1]+a[i-2];

}

cin>>n;

cout<<a[n-1]<<endl;

}


