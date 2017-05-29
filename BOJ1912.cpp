//https://www.acmicpc.net/problem/1912

#include <cstdio>

#define MAX_LEN 100001

int max(int a, int b) {
    return a > b ? a : b;
}

int number[MAX_LEN];
int dp[MAX_LEN];

int main(void) {
    int N;
    scanf("%d", &N);

    for(int n = 1; n <= N; n++)
        scanf("%d", &number[n]);

    dp[1] = number[1];
    int result = dp[1];

    for(int n = 2; n <= N; n++) {
        dp[n] = max(dp[n - 1] + number[n], number[n]);
        result = max(dp[n], result);
    }

    printf("%d\n", result);
    return 0;
}
