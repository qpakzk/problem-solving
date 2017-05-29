//https://www.acmicpc.net/problem/2163

#include <cstdio>
#define MAX_LEN 301

int dp[MAX_LEN][MAX_LEN];

int min(int a, int b) {
    if(a < b)
        return a;
    else
        return b;
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    dp[1][1] = 0;

    for(int n = 2; n <= N; n++)
        dp[n][1] = n - 1;

    for(int m = 2; m <= M; m++)
        dp[1][m] = m - 1;

    for(int n = 2; n <= N; n++)
        for(int m = 2; m <= M; m++)
            dp[n][m] = 1 + min(dp[1][m] + dp[n - 1][m], dp[n][1] + dp[n][m - 1]);
/*
    for(int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++)
            printf("%d ", dp[n][m]);
        printf("\n");
    }
*/
    printf("%d\n", dp[N][M]);

    return 0;
}
