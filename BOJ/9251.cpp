//https://www.acmicpc.net/problem/9251

#include <cstdio>
#include <cstring>
#define MAX_LEN 1001

char str1[MAX_LEN], str2[MAX_LEN];
int dp[MAX_LEN][MAX_LEN];

int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}
int main(void) {
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = (int) strlen(str1);
    int len2 = (int) strlen(str2);

    for(int i = 1; i <= len1; i++)
        for(int j = 1; j <= len2; j++)
            dp[i][j] = (str1[i - 1] == str2[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    printf("%d\n", dp[len1][len2]);
    return 0;
}
