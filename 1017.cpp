#include <iostream>

using namespace std;

int main(){
    int c;
    int s;
    int n,m;
    int count;
    cin>>s;
    while(s--){

        c=0;
        while(cin>>n>>m){
            c++;
            count=0;
            if(n==0&&m==n)
                break;
            for(int a=1;a<n;a++)
                for(int b=a+1;b<n;b++)
                    if((a*a+b*b +m)%(a*b)==0)
                        count++;
            cout<<"Case "<<c<<": "<<count<<endl;
        }
        if(s!=0)
            cout<<endl;
    }
    return 0;
}