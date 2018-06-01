
#include<iostream>
using namespace std;
int main()
{
    double a,n=0,t=12;
    while(t--)
    {
        cin>>a;
        n+=a;
    }
    cout<<"$"<<n/12<<endl;
    return 0;
}