//https://www.acmicpc.net/problem/1992
#include <stdio.h>
typedef enum {FALSE, TRUE} BOOLEAN;

int image[65][65];

void compress(int x1, int x2, int y1, int y2) {
	int i, j;
	BOOLEAN isZero = TRUE, isOne = TRUE;
	for(i = x1; (i <= x2) && isZero; i++) {
		for(j = y1; (j <= y2) && isZero; j++) {
			if(image[i][j] != 0)
				isZero = FALSE;	
		}
	}
	
	if(isZero != TRUE) {
		for(i = x1; (i <= x2) && isOne; i++) {
			for(j = y1; (j <= y2) && isOne; j++) {
				if(image[i][j] != 1)
					isOne = FALSE;	
			}
		}
	}	

	if(isZero == TRUE) {
		printf("0");
		return;
	}
	else if(isOne == TRUE) {
		printf("1");
		return;
	}
	else { 
		printf("(");
		compress(x1, (x1 + x2) / 2, y1, (y1 + y2) / 2);
		compress(x1, (x1 + x2) / 2, (y1 + y2) / 2 + 1, y2);
		compress((x1 + x2) / 2 + 1, x2, y1, (y1 + y2) / 2);
		compress((x1 + x2) / 2 + 1, x2, (y1 + y2) / 2 + 1, y2);
		printf(")");
	}	
}

int main(void) {
	int N, i, j;
	char c;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			scanf("%c", &c);
			while(c == '\n')
				scanf("%c", &c);
			image[i][j] = c - 48;
		}	
	}

	printf("");
	compress(1, N, 1, N);
	printf("\n");
	return 0;
}
