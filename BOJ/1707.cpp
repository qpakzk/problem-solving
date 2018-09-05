#include <cstdio>
#include <vector>
#define MAXLEN 200001
using namespace std;

vector<int> g[MAXLEN];
int vec[MAXLEN];

void dfs(int x, int y) {
    vec[x] = vec[y] ? 3 - vec[y] : 1;

    for(int v : g[x])
        if(!vec[v])
            dfs(v, x);
}
int main(void) {
    int K;
    scanf("%d", &K);

    while(K--) {
        for(int i = 0; i < MAXLEN; i++) {
            g[i].clear();
            vec[i] = 0;
        }

        int V, E;
        scanf("%d%d", &V, &E);
        while(E--) {
            int e1, e2;
            scanf("%d%d", &e1, &e2);
            g[e1].push_back(e2);
            g[e2].push_back(e1);
        }

        for(int i = 1; i <= V; i++)
            if(!vec[i])
                dfs(i, 0);

        int t = 0;
        for(int i = 1; i <= V; i++)
            for(int j : g[i])
                t += (vec[i] == vec[j]);
        if(t)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
