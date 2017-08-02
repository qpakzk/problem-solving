 //https://www.acmicpc.net/problem/13398

#include <iostream>
#include <algorithm>
#define MAX_LEN 100001
using namespace std;

int input[MAX_LEN];
long long dp[2][MAX_LEN];
int N;
long long answer;

long long max3(long long data1, long long data2, long long data3) {
    long long ret = max(data1, data2);
    ret = max(ret, data3);

    return ret;
}
int main(void) {
    cin >> N;

    for(int i = 1; i <= N; i++)
        cin >> input[i];

    dp[0][1] = input[1];
    dp[1][1] = input[1];
    answer = dp[0][1];

    for(int i = 2; i <= N; i++) {
        if(dp[0][i - 1] < 0)
            dp[0][i] = input[i];
        else
            dp[0][i] = dp[0][i - 1] + input[i];

        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + input[i]);
        answer = max3(answer, dp[0][i], dp[1][i]);
    }

    cout << answer << endl;
    return 0;
}
