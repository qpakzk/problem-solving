//https://www.acmicpc.net/problem/11066

#include <iostream>
#include <cstring>
#define MAX_SIZE 501
using namespace std;

int T, K;
int input[MAX_SIZE];
long long dp[MAX_SIZE][MAX_SIZE];
long long cost[MAX_SIZE][MAX_SIZE];

int main(void) {
    cin >> T;

    while(T--) {
        memset(input, 0, sizeof(input));
        memset(cost, 0, sizeof(cost));
        memset(dp, 0, sizeof(dp));

        cin >> K;
        for(int i = 1; i <= K; i++)
            cin >> input[i];

        for(int i = 1; i <= K; i++)
            cost[i][i] = input[i];

        for(int i = 1; i <= K; i++)
            for(int j = i + 1; j <= K; j++)
                cost[i][j] = cost[i][j - 1] + input[j];

        for(int diagonal = 1; diagonal < K; diagonal++)
            for(int i = 1; i < K; i++) {
                int j = i + diagonal;
                if(j <= K) {
                    for(int k = i; k < j; k++) {
                        if(dp[i][j] == 0 || dp[i][j] > dp[i][k] + dp[k + 1][j] + cost[i][j])
                            dp[i][j] = dp[i][k] + dp[k + 1][j] + cost[i][j];
                    }
                }


            }

        cout << dp[1][K] << endl;
    }
    return 0;
}
