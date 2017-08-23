//https://www.acmicpc.net/problem/11053

#include <cstdio>
#define MAX_LEN 1001

int input[MAX_LEN];
int LIS[MAX_LEN];

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        scanf("%d", &input[i]);

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        LIS[i] = 1;

        for(int j = 1; j <= i - 1; j++)
            if(input[j] < input[i])
                if(LIS[j] + 1 > LIS[i])
                    LIS[i] = LIS[j] + 1;

        if(ans < LIS[i])
            ans = LIS[i];
    }

    printf("%d\n", ans);
    return 0;
}