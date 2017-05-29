//https://www.acmicpc.net/problem/2167

#include <cstdio>
#define MAX_LEN 301

int matrix[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
int main(void) {
    int M, N;
    scanf("%d%d", &M, &N);

    for(int m = 1; m <= M; m++)
        for(int n = 1; n <= N; n++)
            scanf("%d", &matrix[m][n]);

    dp[1][1] = matrix[1][1];
    for(int n = 2; n <= N; n++)
        dp[1][n] = dp[1][n - 1] + matrix[1][n];

    for(int m = 2; m <= M; m++)
        dp[m][1] = dp[m - 1][1] + matrix[m][1];

    for(int m = 2; m <= M; m++)
        for(int n = 2; n <= N; n++)
            dp[m][n] = matrix[m][n] + dp[m - 1][n] + dp[m][n - 1] - dp[m - 1][n - 1];

    int K;
    scanf("%d", &K);

    for(int k = 1; k <= K; k++) {
        int i, j, x, y;
        scanf("%d%d%d%d", &i, &j, &x, &y);
        int result = dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1];
        printf("%d\n", result);
    }

    return 0;
}
