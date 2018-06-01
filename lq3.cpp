#include<iostream>
using namespace std;

int measure(int a,int b)  
{         
    while(a != b)  
    {  
        if(a>b)  
        {  
            a = a - b;  
        }  
        else   
        {  
            b = b - a;  
        }  
    }  
    return a;  
}  




int main(int argc, char const *argv[]){


	int a,b,c;
	cin >> a >> b >> c;
	int d = a * b /measure(a,b);
	cout << d * c /measure(d,c) << endl;
	
	return 0;
}