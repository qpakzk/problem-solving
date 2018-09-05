//https://www.acmicpc.net/problem/10844

#include <iostream>
#define MOD  1000000000
#define HEAD 10
#define MAX_LEN 101
using namespace std;

int N;
long long dp[MAX_LEN][HEAD];

int main(void) {
    cin >> N;

    for(int i = 0; i < HEAD; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1];
        for(int j = 1; j <= 8; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        dp[i][9] = dp[i - 1][8];
    }

    long long answer = 0;
    for(int i = 1; i < HEAD; i++) {
        answer += dp[N][i];
        answer %= MOD;
    }
    cout << answer << endl;
    return 0;
}
