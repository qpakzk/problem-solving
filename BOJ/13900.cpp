//https://www.acmicpc.net/problem/13900

#include <cstdio>
#include <algorithm>
#define MAX 100000

using namespace std;

int input[MAX];

int main(void) {
    int N;
    long long sum, ans;

    scanf("%d", &N);

    sum = 0;
    for(int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        sum += n;
        input[i] = n;
    }

    sort(input, input + N);

    ans = 0;
    for(int i = 0; i < N - 1; i++) {
        sum -= input[i];
        ans += sum * input[i];
    }
    printf("%lld\n", ans);
    return 0;
}
