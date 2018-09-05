//https://www.acmicpc.net/problem/2309
#include <stdio.h>
#include <stdlib.h>
typedef enum {FALSE, TRUE} BOOLEAN;

int comp(const void *a, const void *b) {
	if(*(int *)a < *(int *)b)
		return -1;
	else if(*(int *)a == *(int *)b)
		return 0;
	else 
		return 1;
}

int main(void) {
	int men[9], real[7];
	int i, j, sum = 0, temp1, temp2, drop1, drop2;
	BOOLEAN is100;
	for(i = 0; i < 9; i++) {
		scanf("%d", &men[i]);
		sum += men[i];
	}
	is100 = FALSE;	
	for(i = 0; (i < 8) && (!is100); i++) {
		temp1 = sum;
		temp1 -= men[i];
		drop1 = i;
		if(temp1 <= 100)
			continue;
		for(j = i + 1; j < 9; j++) {
			temp2 = temp1;
		   	temp2 -= men[j];
			
			if(temp2 == 100) {
				drop2 = j;
				is100 = TRUE;
				break;
			}
		}
	}
	
	for(i = 0, j = 0; i < 9; i++) {
		if(i == drop1 || i == drop2)
			continue;
		real[j++] = men[i];	
	}	
	qsort(real, 7, sizeof(int), comp);
	
	for(i = 0; i < 7; i++)
		printf("%d\n", real[i]);

	return 0;
}
