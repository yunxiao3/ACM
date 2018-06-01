#include <iostream>
using namespace std;

int max_yueshu(int a, int b)
{
    int temp = 0;
    while((temp = a%b) != 0)
    {
        a = b;
        b = temp;
    }
    return b;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int count = 0;
    int min = a<b?a:b;
    int max = a>b?a:b;
    for(int i = min; i <= max; i++)
    {
        if (a*b%i == 0 && max_yueshu(i, a*b/i) == a)
        {
            count++;
        }
    }
    cout<<count<<endl;
}


