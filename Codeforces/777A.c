//http://codeforces.com/problemset/problem/777/A
#include <stdio.h>

int main(void) {
	int n, x;
	int turn, place;
	scanf("%d\n%d", &n, &x);
	
	turn = n % 6;
		
	switch(turn) {
		case 0:
			place = x;
			break;
		case 1:
			switch(x) {
				case 0:
					place = 1;
					break;
				case 1:
					place = 0;
					break;
				case 2:
					place = 2;
					break;
			}
			break;
		case 2:
			switch(x) {
				case 0:
					place = 1;
					break;
				case 1:
					place = 2;
					break;
				case 2:
					place = 0;
					break;
			}
			break;
		case 3:
			switch(x) {
				case 0:
					place = 2;
					break;
				case 1:
					place = 1;
					break;
				case 2:
					place = 0;
					break;
			}
			break;
		case 4:
			switch(x) {
				case 0:
					place = 2;
					break;
				case 1:
					place = 0;
					break;
				case 2:
					place = 1;
					break;
			}
			break;
		case 5:
			switch(x) {
				case 0:
					place = 0;
					break;
				case 1:
					place = 2;
					break;
				case 2:
					place = 1;
					break;
			}
			break;
	}

	printf("%d\n", place);
	return 0;
}
