//https://www.acmicpc.net/problem/10250
#include <cstdio>

int main(void) {
	int T, H, W, N;
	int number, floor;	
	scanf("%d", &T);

	for(int loop = 0; loop < T; loop++) {
		scanf("%d%d%d", &H, &W, &N);
		number = N / H;
		if(N % H != 0) {
			number += 1;
			floor = (N % H) * 100;
		}
		else {
			floor = H * 100;
		}
		int room = floor + number;
		printf("%d\n", room);
	}
	return 0;
}
