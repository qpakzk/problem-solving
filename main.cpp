//https://www.acmicpc.net/problem/11055

#include <cstdio>
#define MAX_LEN 1001

int input[MAX_LEN];
int sum[MAX_LEN];

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &input[i]);
        sum[i] = input[i];
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i - 1; j++) {
            if(input[j] < input[i])
                if(sum[j] + input[i] > sum[i])
                    sum[i] = sum[j] + input[i];
        }

        if(ans < sum[i])
            ans = sum[i];
    }

    printf("%d\n", ans);

    return 0;
}