//https://www.acmicpc.net/problem/10989
#include <stdio.h>
#include <stdlib.h>

int num[1000001];

int main(void) {
	int N;
	scanf("%d",  &N);

	int input;
	for(int i = 0; i < N; i++) {
		scanf("%d", &input);
		num[input]++;
	}

	for(int i = 1; i <= 1000000; i++) {
		for(int j = 0; j < num[i]; j++) 	 
			printf("%d\n", i);
	}
	return 0;
}
