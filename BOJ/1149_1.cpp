#include <cstdio>

#define MAX_N 1001

int RGB[MAX_N][3];
int dp[MAX_N][3];

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d%d%d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
		
	/*
	 * dp[n][0] = min(dp[n - 1][1], dp[n - 1][2]) + RGB[n][0]
	 * dp[n][1] = min(dp[n - 1][0], dp[n - 1][2]) + RGB[n][1]
	 * dp[n][2] = min(dp[n - 1][0], dp[n - 1][1]) + RGB[n][2]
	 * result = min(dp[n][0], dp[n][2], dp[n][3])
	 */

	dp[1][0] = RGB[1][0];
	dp[1][1] = RGB[1][1];
	dp[1][2] = RGB[1][2];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + RGB[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + RGB[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + RGB[i][2];
	}

	int result = dp[N][0];
	if (result > dp[N][1])
		result = dp[N][1];
	if (result > dp[N][2])
		result = dp[N][2];

	printf("%d\n", result);
	return 0;
}