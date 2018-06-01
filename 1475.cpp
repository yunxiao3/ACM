#include<iostream>

#include<string>

#include<math.h>

using namespace std;



int main()

{

    string ans;

    int m;

    cin>>ans>>m;

    int sum = 0;

    int l = ans.length();

    for(int i=0;i<l;i++)

    {

        if(ans[l-i-1] >= 'A' && ans[l-i-1] <= 'G')

        {

            sum += (ans[l-i-1]-55)*pow(m,i);

        }

        else

        sum += (ans[l-i-1] - '0')*pow(m,i);

    }

    cout<<sum;

}



