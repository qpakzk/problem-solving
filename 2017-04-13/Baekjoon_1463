#include <cstdio>
#include <cstring>

#define MAX_N 1000001

int min2(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int min3(int a, int b, int c) {
	int min = min2(a, b);
	min = min2(min, c);

	return min;
}

int count[MAX_N];
int main(void) {
	memset(count, -1, sizeof(count));
	count[1] = 0;
	count[2] = 1;
	count[3] = 1;
	
	int N;
	scanf("%d", &N);
	
	for (int i = 4; i <= N; i++) {
		if (i % 6 == 0)
			count[i] = min3(count[i / 2], count[i / 3], count[i - 1]) + 1;
		else if (i % 2 == 0)
			count[i] = min2(count[i / 2], count[i - 1]) + 1;
		else if (i % 3 == 0)
			count[i] = min2(count[i / 3], count[i - 1]) + 1;
		else
			count[i] = count[i - 1] + 1;
	}

	printf("%d", count[N]);

	return 0;
}
