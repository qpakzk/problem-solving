//https://www.acmicpc.net/problem/2605
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, i, j, *line, ticket;
	scanf("%d", &N);
	line = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++) {
		scanf("%d", &ticket);
		if(ticket == 0)
			line[i] = i + 1;
		else {
			for(j = i; j > i - ticket; j--)
				line[j] = line[j - 1];
			line[i - ticket] = i + 1;
		}
	}

	for(i = 0; i < N; i++) 
		printf("%d ", line[i]);
	printf("\n");	

	free(line);
	return 0;
}	
