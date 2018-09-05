//https://www.acmicpc.net/problem/12852

#include <iostream>
#include <cstring>
#include <climits>
#define MAX_LEN 1000001

using namespace std;

int dp[MAX_LEN];
int pre[MAX_LEN];
int N;

int min(int cur, int n1, int n2, int n3, int p1, int p2, int p3) {
    int ret = n1;
    pre[cur] = p1;
    if(ret > n2) {
        ret = n2;
        pre[cur] = p2;
    }

    if(ret > n3) {
        ret = n3;
        pre[cur] = p3;
    }

    return ret;
}
int main(void) {
    cin >> N;

    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));

    int div2, div3, sub1;
    int pre1, pre2, pre3;
    for(int i = 2; i <= N; i++) {
        if(i % 2 == 0) {
            pre1 = i / 2;
            div2 = dp[pre1] + 1;
        }
        else {
            pre1 = INT_MAX;
            div2 = INT_MAX;
        }

        if(i % 3 == 0) {
            pre2 = i / 3;
            div3 = dp[pre2] + 1;
        }
        else {
            pre2 = INT_MAX;
            div3 = INT_MAX;
        }

        pre3 = i - 1;
        sub1 = dp[pre3] + 1;

        dp[i] = min(i, div2, div3, sub1, pre1, pre2, pre3);

    }

    cout << dp[N] << endl;

    cout << N << " ";
    int idx = pre[N];
    while(idx >= 1) {
        cout << idx << " ";
        if(idx == 1)
            break;
        idx = pre[idx];
    }

    return 0;
}
