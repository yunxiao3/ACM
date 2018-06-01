#include<cstdio>

using namespace std;

int main()

{

int x,i;

char c;

bool tf=true;

scanf("%d",&x);

for (i=2;i<=x/2;i++)

   if (x%i==0)

       tf=false;

if (tf==1)

   c='t';

else

   c='n';

printf("\\%c",c);

return 0;

}


