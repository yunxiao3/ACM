#include <cstdio>

int main(int argc, char const *argv[]){

	while(true){
		int N = 0;
		int sum = 0, num = 0;

		scanf("%d",&N);
		if(N == 0)
			break;

		for (int i = 0; i < N; ++i){
			scanf("%d",&num);
			sum += num;
		}

		printf("%d\n", sum);


	}

	
	return 0;
}