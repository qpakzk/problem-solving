//https://www.acmicpc.net/problem/2293

#include <cstdio>
#define MAX_N 101
#define MAX_K 10001

int input[MAX_N];
int dp[MAX_K];
int dp_temp[MAX_K];

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    for(int n = 1; n <= N; n++)
        scanf("%d", &input[n]);

    for(int k = 1; k <= K; k++) {
        if(k < input[1])
            dp[k] = 0;
        else if(k == input[1])
            dp[k] = 1;
        else
            dp[k] = dp[k - input[1]];
    }

/*
    for(int k = 1; k <= K; k++)
        printf("%d ", dp[k]);
    printf("\n");
*/

    for(int n = 2; n <= N; n++) {
        for(int k = 1; k <= K; k++) {
            if(k < input[n])
                dp_temp[k] = dp[k];
            else if(k == input[n])
                dp_temp[k] = dp[k] + 1;
            else
                dp_temp[k] = dp[k] + dp_temp[k - input[n]];
        }

        for(int k = 1; k <= K; k++)
            dp[k] = dp_temp[k];

        /*
        for(int k = 1; k <= K; k++)
            printf("%d ", dp[k]);
        printf("\n");
        */
    }

    printf("%d\n", dp[K]);

    return 0;
}
