//https://www.acmicpc.net/problem/3114

#include <cstdio>
#include <climits>

#define MAXLEN 1501
int A[MAXLEN][MAXLEN];
int B[MAXLEN][MAXLEN];
int dp[MAXLEN][MAXLEN];
char input[4];
int main(void) {
    int R, C;

    scanf("%d%d", &R, &C);
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            scanf("%s", input);

            if(input[0] == 'A')
                sscanf(input + 1, "%d", &A[r][c]);
            else
                sscanf(input + 1, "%d", &B[r][c]);

            A[r][c] += A[r][c - 1];
            B[r][c] += B[r - 1][c];

            dp[r][c] = (r == 1 && c == 1) ? 0 : -INT_MAX;

            if(r > 1 && dp[r][c] < dp[r - 1][c] + A[r][c - 1])
                dp[r][c] = dp[r - 1][c] + A[r][c - 1];
            if(c > 1 && dp[r][c] < dp[r][c - 1] + B[r - 1][c])
                dp[r][c] = dp[r][c - 1] + B[r - 1][c];
            if(r > 1 && c > 1 && dp[r][c] < dp[r - 1][c - 1] + A[r][c - 1] + B[r - 1][c])
                dp[r][c] = dp[r - 1][c - 1] + A[r][c - 1] + B[r - 1][c];
        }
    }

    printf("%d", dp[R][C]);
    return 0;
}
