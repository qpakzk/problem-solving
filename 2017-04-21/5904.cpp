#include <cstdio>

char moo(int N) {
    int m = 1, d, i;
    while(m < N) {
        for(i = d = 3; m + d < N;)
            d = d * 2 + (++i);
        m += (d - i) / 2 + i;
    }

    return N == m ? 'm' : 'o';
}
int main(void) {
    int N;
    scanf("%d", &N);
    printf("%c\n", moo(N));
    return 0;
}
