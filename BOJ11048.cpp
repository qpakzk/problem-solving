//https://www.acmicpc.net/problem/11048

#include <iostream>
#include <algorithm>
#define MAX_SIZE 1001

using namespace std;
int N, M;

int input[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

int max3(int n1, int n2, int n3) {
    int ret = n1;

    if(ret < n2)
        ret = n2;

    if(ret < n3)
        ret = n3;

    return ret;
}

int main(void) {
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> input[i][j];

    dp[1][1] = input[1][1];
    for(int i = 2; i <= N; i++)
        dp[i][1] = dp[i - 1][1] + input[i][1];
    for(int j = 2; j <= M; j++)
        dp[1][j] += dp[1][j - 1] + input[1][j];

    for(int i = 2; i <= N; i++)
        for(int j = 2; j <= M; j++)
            dp[i][j] = max3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + input[i][j];
    cout << dp[N][M] << endl;
    return 0;
}
