//https://www.acmicpc.net/problem/1913

#include <cstdio>
#define MAX_LEN 1000
using namespace std;

struct answer {
    int x, y;
};

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1};

int main(void) {
    int N, target;
    int square[MAX_LEN][MAX_LEN];

    scanf("%d\n%d", &N, &target);

    int number = N * N;

    int iter = N, dir = 1;
    int x = 0, y = 1;
    answer ans;
    while (1) {
        for(int m = 0; m < iter; m++) {
            x += dir;
            if(target == number) {
                ans.x = x;
                ans.y = y;
            }

            square[x][y] = number;
            number--;
        }

        iter--;
        if(iter < 1)
            break;

        for(int m = 0; m < iter; m++) {
            y += dir;
            if(target == number) {
                ans.x = x;
                ans.y = y;
            }

            square[x][y] = number;
            number--;
        }

        dir *= -1;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            printf("%d ", square[i][j]);
        printf("\n");
    }

    printf("%d %d\n", ans.x, ans.y);
    return 0;
}
