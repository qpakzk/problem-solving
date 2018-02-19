#include <iostream>
#include <cstring>
#define MAX 50
using namespace std;

int T, M, N, K, X, Y;
int map[MAX][MAX];

void dfs(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N) {
        if (map[x][y]) {
            map[x][y] = 0;
            dfs(x + 1, y);
            dfs(x, y + 1);
            dfs(x - 1, y);
            dfs(x, y - 1);
        }
    }
}

int main() {
    int res;
    cin >> T;
    while(T--) {
        memset(map, 0, sizeof(map));
        res = 0;
        cin >> M >> N >> K;

        for (int k = 0; k < K; k++) {
            cin >> X >> Y;
            map[X][Y] = 1;
        }

        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if (map[i][j]) {
                    map[i][j] = 0;
                    res++;
                    dfs(i + 1, j);
                    dfs(i, j + 1);
                    dfs(i - 1, j);
                    dfs(i, j - 1);

                }
            }

        }

        cout << res << endl;
    }
    return 0;
}