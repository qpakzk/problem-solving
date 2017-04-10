/*
 * https://www.acmicpc.net/problem/2579
 */
#include <cstdio>
#include <cstring>

#define MAXLEN 301

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}
int main() {
    int N;
    int score[MAXLEN];
    int dp[2][MAXLEN];
    int result;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &score[i]);
    /* result = max(dp[0][N], dp[1][N])
     * dp[0][x] = dp[1][x - 1] + score[x]
     * dp[1][x] = max(dp[0][x - 2], dp[1][x - 2]) + score[x]
     */

    memset(dp, 0, sizeof(dp));
    dp[0][1] = score[1];

    if(N > 1) {
        dp[0][2] = dp[0][1] + score[2];
        dp[1][2] = score[2];

        for(int x = 3; x <= N; x++) {
            dp[0][x] = dp[1][x - 1] + score[x];
            dp[1][x] = max(dp[0][x - 2], dp[1][x - 2]) + score[x];
        }
    }

    result = max(dp[0][N], dp[1][N]);
    printf("%d\n", result);

    return 0;
}
