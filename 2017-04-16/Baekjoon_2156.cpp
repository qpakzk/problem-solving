//https://www.acmicpc.net/problem/2156
#include <cstdio>

#define MAX_LEN 10001

int input[MAX_LEN];
int dp[MAX_LEN][2];

int max2(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int max3(int a, int b, int c) {
    int result = max2(a, b);
    result = max2(result, c);

    return result;
}

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &input[i]);

    int result = 0;
    dp[1][0] = input[1];
    result = max2(result, dp[1][0]);

    if(N > 1) {
        dp[2][0] = dp[1][0] + input[2];
        dp[2][1] = input[2];
        result = max3(result, dp[2][0], dp[2][1]);

        for (int i = 3; i <= N; i++) {
            dp[i][0] = dp[i - 1][1] + input[i];
            int max = max2(dp[i - 2][0], dp[i - 2][1]);
            for(int j = 3; j <= i - 1; j++) {
                max = max3(max, dp[i - j][0], dp[i - j][1]);
            }
            dp[i][1] = max + input[i];

            result = max3(result, dp[i][0], dp[i][1]);
        }
    }
/*
    for(int i = 1; i <= N; i++)
        printf("%d ", dp[i][0]);
    printf("\n");

    for(int i = 1; i <= N; i++)
        printf("%d ", dp[i][1]);
    printf("\n");
*/
    printf("%d\n", result);
    return 0;
}
