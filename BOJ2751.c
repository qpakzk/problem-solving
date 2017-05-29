//https://www.acmicpc.net/problem/2751
#include <stdio.h>
#include <stdlib.h>

int num[2000001];

int main(void) {
	int N;
	scanf("%d",  &N);

	int input;
	for(int i = 0; i < N; i++) {
		scanf("%d", &input);
		int idx;
		num[input + 1000000]++;
	}

	for(int i = 0; i <= 2000000; i++) {
		if(num[i] == 1) 
			printf("%d\n", i - 1000000);
	}
	return 0;
}
