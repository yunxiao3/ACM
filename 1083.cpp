#include <iostream>

using namespace std;

int main()

{

int n,i=1,hang;

cin>>n;

int sum=0;

while(sum<n)

{

sum+=i;

i++;

}

i=i-1;

hang=i;

if(i%2==0)

{

i=i-(sum-n)-1;

cout<<1+i<<"/"<<hang-i;

}

else

{

i=i-(sum-n)-1;

cout<<hang-i<<"/"<<1+i;

}

return 0;

}
