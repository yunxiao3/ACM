#include <cstdio>

int main(int argc, char const *argv[]){

	int N;

	while(scanf("%d",&N) != EOF){

		int sum = 0, num = 0;

		for (int i = 0; i < N; ++i){
			scanf("%d",&num);
			sum += num;
		}

		printf("%d\n", sum);
	}
	
	return 0;
}