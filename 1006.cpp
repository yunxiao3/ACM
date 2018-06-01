#include <cstdio>
#include<cmath>
int D;


bool ishappy(double h, double m, double s){

	if (fabs(h - m) <= D )
		return false;
	if (fabs(h - s) <= D )
	return false;
	if (fabs(s - m) <= D )
		return false;

	if (fabs(h - m) >=  360 - D )
		return false;
	if (fabs(h - s) >= 360 - D )
	return false;
	if (fabs(s - m) >= 360 - D )
		return false;

	return true;
}




int main(int argc, char const *argv[]){

	while(true){

		scanf("%d",&D); if( D == -1) break;

		int hours = 0, minutes = 0, seconds = 0;
		double dh = 0, dm = 0, ds = 0;
		double degree = 0.1 / 12;

		int ans = 0;

		while(true){
			

			seconds ++;
			ds += 6.0;
			dm += 0.1;;
			dh += degree;
			if(seconds == 60){
				ds = 0;
				seconds = 0;
				minutes ++;
			}

			if (minutes == 60){
				dm = 0;
				minutes = 0;
				hours ++;
			}

			if(hours == 12)
				break;


			if(ishappy(dh,dm,ds)){
				ans ++;
			}


		}


		printf("%.3f\n", ans  / 36.0 / 12 );

	}









	
	return 0;

}