#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;


bool inq[14] = {false};
int ans = 0;
int a[14]; 



int DFS(int dep){

		if (dep==13) {
        	if (a[10]==a[11]*a[12]){ 
        		ans++;
        		for (int i = 1; i <= 12; ++i)
        		{
        			cout << a[i] << " " ;
        		}

        		cout << endl;
        	}
        	return 0 ;
   		}

	    if (dep==10) {
	        if (a[7]*a[8]!=a[9]) return 0;
	    }
	    if (dep==7) {
	        if (a[4]-a[5]!=a[6]) return 0;
	    }
	    if (dep==4) {
	        if (a[1]+a[2]!=a[3]) return 0;
	    }



	    for (int i = 1; i <= 13; ++i){


	    	if (!inq[i]){
	    		
	    		inq[i] = true;
	    		a[dep] = i;
	    		DFS(dep + 1);
	    		inq[i] = false; 

	    	}
	    	
	    }
	




	}






int main(int argc, char const *argv[]){

	int i ; cin >> i;
	
	DFS(1);

	cout << ans ;
	
	return 0;
}