//https://www.acmicpc.net/problem/9252
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define MAX_LEN 1001

using namespace std;

char str1[MAX_LEN], str2[MAX_LEN];
int dp[MAX_LEN][MAX_LEN];

int main(void) {
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = (int) strlen(str1);
    int len2 = (int) strlen(str2);

    for(int i = 1; i <= len1; i++)
        for(int j = 1; j <= len2; j++)
            dp[i][j] = (str1[i - 1] == str2[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    printf("%d\n", dp[len1][len2]);

    stack<char> S;

    int i = len1, j = len2;

    while(i != 0 && j != 0) {
        if(str1[i - 1] == str2[j - 1]) {
            if (dp[i][j] == dp[i - 1][j - 1] + 1) {
                S.push(str1[i - 1]);
                i--;
                j--;
            }
        }
        else {
            if(dp[i][j] == dp[i - 1][j])
                i--;
            else
                j--;
        }
    }

    while(!S.empty()) {
        printf("%c", S.top());
        S.pop();
    }

    return 0;
}