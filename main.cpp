//https://www.acmicpc.net/problem/11051

#include <cstdio>
#define MAX 1001
#define MOD 10007

int d[MAX][MAX];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++)
        d[i][0] = d[i][i] = 1;

    for(int n = 2; n <= N; n++) {
        for(int k = 1; k <= K; k++)
            d[n][k] = (d[n - 1][k - 1] + d[n - 1][k]) % MOD;
    }

    printf("%d\n", d[N][K]);
    return 0;
}