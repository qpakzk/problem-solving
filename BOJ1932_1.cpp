//https://www.acmicpc.net/problem/1932

#include <cstdio>
#define MAX_SIZE 501

int input[MAX_SIZE];
int dp[MAX_SIZE];
int dp_next[MAX_SIZE];

int max(int a, int b) {
    if(a < b)
        return b;
    else
        return a;
}

int main(void) {
    int n;
    scanf("%d", &n);

    /*
     * (i) x >=2 && x <= n - 1
     *  dp[x] = max(dp[x - 1], dp[x]) + input[x]
     * (ii) x == 1
     *  dp[x] += input[x]
     * (iii) x == n
     *  dp[x] += input[x - 1]
     */
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            scanf("%d", &input[j]);
        for(int j = 1; j <= i; j++) {
            if(j == 1)
                dp_next[j] = dp[j] + input[j];
            else if(j >= 2 && j <= n - 1)
                dp_next[j] = max(dp[j - 1], dp[j]) + input[j];
            else if(j == n)
                dp_next[j] = dp[j - 1] + input[j];
        }

        for(int j = 1; j <= n; j++)
            dp[j] = dp_next[j];
    }

    int result = dp[1];

    for(int i = 2; i <= n; i++)
        if(result < dp[i])
            result = dp[i];
    printf("%d\n", result);
    return 0;
}
