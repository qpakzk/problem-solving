//https://www.acmicpc.net/problem/1010

#include <cstdio>
#define MAX_LEN 30

long long dp[MAX_LEN][MAX_LEN];

int main(void) {
    int T;
    scanf("%d", &T);

    for(int i = 1; i < MAX_LEN; i++)
        dp[i][i] = 1;
    for(int i = 2; i < MAX_LEN; i++)
        dp[1][i] = i;

    /*
     * dp[x][y] = dp[x - 1][y - 1] + dp[x - 1][y - 2]
     */
    while(T--) {
        int N, M;
        scanf("%d%d", &N, &M);
        for(int x = 2; x <= N; x++)
            for(int y = 3; y <= M; y++)
                if(dp[x][y] == 0)
                    for(int k = x - 1; k <= y - 1; k++)
                        dp[x][y] += dp[x - 1][k];

        printf("%lld\n", dp[N][M]);
    }


    return 0;
}
