/*
 * https://www.acmicpc.net/problem/2193
 */

#include <cstdio>
#define MAXLEN 91

long long dp[MAXLEN][2];

int main(void) {
    int N;
    scanf("%d", &N);
    /*
     * dp[n][0] = dp[n - 1][0] + dp[n - 1][1]
     * dp[n][1] = dp[n - 1][0]
     */

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    long long result = dp[N][0] + dp[N][1];
    printf("%lld\n", result);
    return 0;
}
