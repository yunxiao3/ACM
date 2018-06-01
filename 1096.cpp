	#include <cstdio>

	int main(int argc, char const *argv[]){

		int N = 0; scanf("%d",&N);

		for (int i = 0; i < N; ++i){

			int sum = 0, num = 0, M = 0;
			scanf("%d",&M);

			for (int i = 0; i < M; ++i){
				scanf("%d",&num);
				sum += num;
			}

			printf("%d\n", sum);

			if (i < N - 1){
				printf("\n");
			}
		}

		return 0;
	}