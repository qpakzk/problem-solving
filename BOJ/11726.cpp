//https://www.acmicpc.net/problem/11726

#include <cstdio>
#define MAX_N 1001

int dp[MAX_N];

int main(void) {
    int n;
    scanf("%d", &n);

    /*
     * dp[n] = dp[n - 1] + dp[n - 2]
     */

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    printf("%d", dp[n]);
    return 0;
}
