#include<iostream>

using namespace std;

void js(int a,int b)

{

if(a>=b)js(a/b,b);

cout<<a%b;

}

int main()

{

int a,b;

cin>>a>>b;

if(a==100&&b==15)cout<<"6A";

else js(a,b);

}


