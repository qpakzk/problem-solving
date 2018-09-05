//https://www.acmicpc.net/problem/1780
#include <stdio.h>
typedef enum {FALSE, TRUE} BOOLEAN;

int paper[2188][2188];
int cnt_1 = 0, cnt0 = 0, cnt1 = 0;

void divide(int x1, int x2, int y1, int y2) {
	BOOLEAN is_One = TRUE, isZero = TRUE, isOne = TRUE;
	int i, j, len, gap;

	for(i = x1; i <= x2 && is_One; i++) {
		for(j = y1; j <= y2 && is_One; j++) {
			if(paper[i][j] != -1)
				is_One = FALSE;	
		}
	}	
	
	if(is_One == FALSE) {
		for(i = x1; i <= x2 && isZero; i++) {
			for(j = y1; j <= y2 && isZero; j++) {
				if(paper[i][j] != 0)
					isZero = FALSE;	
			}
		}	
	}

	if(isZero == FALSE) {
		for(i = x1; i <= x2 && isOne; i++) {
			for(j = y1; j <= y2 && isOne; j++) {
				if(paper[i][j] != 1)
					isOne = FALSE;	
			}
		}	
	}
		
	if(is_One == TRUE)
		cnt_1++;
	else if(isZero == TRUE)
		cnt0++;
	else if(isOne == TRUE)
		cnt1++;
	else {
		len = x2 - x1 + 1;
		gap = len / 3;
		divide(x1, x1 + gap - 1, y1, y1 + gap - 1);
		divide(x1, x1 + gap - 1, y1 + gap, y1 + gap * 2 - 1);
		divide(x1, x1 + gap - 1, y1 + gap * 2, y2);
		divide(x1 + gap, x1 + gap * 2 - 1, y1, y1 + gap - 1);
		divide(x1 + gap, x1 + gap * 2 - 1, y1 + gap, y1 + gap * 2 - 1);
		divide(x1 + gap, x1 + gap * 2 - 1, y1 + gap * 2, y2);
		divide(x1 + gap * 2, x2, y1, y1 + gap - 1);
		divide(x1 + gap * 2, x2, y1 + gap, y1 + gap * 2 - 1);
		divide(x1 + gap * 2, x2, y1 + gap * 2, y2);
	}
}

int main(void) {
	int N, i, j, c;
	BOOLEAN isMinus;
	scanf("%d", &N);
	
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}		
	
	divide(1, N, 1, N);
	printf("%d\n%d\n%d\n", cnt_1, cnt0, cnt1);

	return 0;
}
