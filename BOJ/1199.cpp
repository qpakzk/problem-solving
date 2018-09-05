//https://www.acmicpc.net/problem/1199

#include <cstdio>
#define MAXLEN 1001

int N;
int m[MAXLEN][MAXLEN];

void dfs(int k) {
    for(int i = 1; i <= N; i++) {
        if(m[k][i]) {
            m[k][i]--;
            m[i][k]--;
            dfs(i);
        }
    }
    printf("%d ", k);
}

int main(void) {
    scanf("%d", &N);
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &m[i][j]);
            cnt += m[i][j];
        }

        if(cnt % 2) {
            puts("-1");
            return 0;
        }
    }

    dfs(1);
    return 0;
}
