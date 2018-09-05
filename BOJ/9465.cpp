//https://www.acmicpc.net/problem/9465

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

int main() {
    int dp[2][MAX];
    int T, n;
    cin >> T;

    while(T--) {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++)
                cin >> dp[i][j];
        }

        for(int i = 2; i <= n; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + dp[0][i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + dp[1][i]);
        }

        int result = dp[0][n] > dp[1][n] ? dp[0][n] : dp[1][n];
        cout << result << endl;
    }

    return 0;
}