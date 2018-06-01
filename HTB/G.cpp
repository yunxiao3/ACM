#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

int main(int argc, char const *argv[]){

	double a, b, c, d;
	// scanf("%lf%lf")

	while(cin >> a >> b >> c >> d ){
	


	double x = ( -sqrt(b / d) * c - a) /  ( 1.0 + sqrt(b / d));
	// cout << x << " " << 5 / 3.0 << endl;
	// cout << sqrt((x+a)*(x+a)+b)+sqrt((x+c)*(x+c)+d);
	printf("%.3lf\n",sqrt((x+a)*(x+a)+b)+sqrt((x+c)*(x+c)+d));
}
	
	return 0;
}