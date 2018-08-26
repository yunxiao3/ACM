#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int aaa(int m,int n)
{
	int i,sum;
	sum=1;
	for(i=n;i>=(n-m+1);i--)
		sum*=i;
	return sum;
}
int ccc(int m,int n)
{
	int i,sum;
	sum=1;
	for(i=1;i<=m;i++)
		sum*=i;
	sum=aaa(m,n)/sum;
	return sum;
}
int main()
{
	int m,n,k;
	char letter;
	while(~scanf("%d",&k)&&k)
	{
		while(k--)
		{
			getchar();
			scanf("%c %d%d",&letter,&n,&m);
			if(letter=='A')
				printf("%d\n",aaa(m,n));
			else
				printf("%d\n",ccc(m,n));
		}
	}
	return 0;
}