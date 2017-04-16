//https://www.acmicpc.net/problem/11727

#include <cstdio>
#define MAX_N 1001

int dp[MAX_N][3];

int main(void) {
    int N;
    scanf("%d", &N);

    if(N >= 1) {
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = dp[1][0] + dp[1][1];
    }

    if(N >= 2) {
        dp[2][0] = 2;
        dp[2][1] = 1;
        dp[2][2] = dp[2][0] + dp[2][1];
    }

    if(N >= 3) {
        for(int n = 3; n <= N; n++) {
            dp[n][0] = (dp[n - 1][0] + dp[n - 2][0]) % 10007;
            dp[n][1] = (dp[n - 1][1] + dp[n - 2][0] + dp[n - 2][1] * 2) % 10007;
            dp[n][2] = (dp[n][0] + dp[n][1]) % 10007;
        }
    }

    printf("%d\n", dp[N][2]);

    return 0;
}
