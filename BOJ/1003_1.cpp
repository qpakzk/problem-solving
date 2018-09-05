#include <cstdio>
#include <cstring>

#define MAX_N 41

int count[MAX_N][2];

int main(void) {
	int T;
	scanf("%d", &T);
	memset(count, -1, sizeof(count));

	count[0][0] = 1;
	count[0][1] = 0;

	count[1][0] = 0;
	count[1][1] = 1;


	/*
	 * count[n][0] = count[n - 1][0] + count[n - 2][0]
	 * count[n][1] = count[n - 1][1] + count[n - 2][1]
	 */

	
	while (T--) {
		int N;
		scanf("%d", &N);

		for (int i = 2; i <= N; i++) {
			if (count[i][0] == -1)
				count[i][0] = count[i - 1][0] + count[i - 2][0];
			if (count[i][1] == -1)
				count[i][1] = count[i - 1][1] + count[i - 2][1];
		}

		printf("%d %d\n", count[N][0], count[N][1]);
	}
	
	return 0;
}
