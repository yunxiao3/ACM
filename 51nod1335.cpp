#include <bits/stdc++.h>
using namespace std;
string run(string s,int x,int y)
{
    for(int i=x;i<=(x+y)/2;i++)
        swap(s[i],s[y-i+x]);
    return s;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,b,c;
        cin>>s;
        int x=0,y=0;
        b=s;
        sort(&b[0],&b[0]+b.size());//找到x，这样比较快
        for(int i=0;s[i];i++)//对比。
            if(s[i]>b[i])
            {
                x=y=i;
                break;
            }
        b=s;
        for(int j=x+1;s[j];j++)
            if(s[j]<=s[x])
            {
                c=run(s,x,j);
                if(c<b)
                {
                    b=c;
                    y=j;
                }
            }
           cout << b << endl;
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}
