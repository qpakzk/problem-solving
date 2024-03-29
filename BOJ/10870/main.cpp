// https://www.acmicpc.net/problem/10870

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    int f[21];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    printf("%d\n", f[n]);
    return 0;
}
