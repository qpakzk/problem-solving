//https://www.acmicpc.net/problem/9095

#include <cstdio>
#include <cstring>
#define MAX_NUM 11

int dp[MAX_NUM];

int main(void) {
    int T;

    scanf("%d", &T);

    /*
     * dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3]
     */

    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    dp[1] = dp[0];//1
    dp[2] = dp[1] + dp[0];//2

    while(T--) {
        int n;
        scanf("%d", &n);

        for(int i = 3; i <= n; i++)
            if(dp[i] == -1)
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        printf("%d\n", dp[n]);
    }
    return 0;
}
