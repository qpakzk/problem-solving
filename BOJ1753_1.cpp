//https://www.acmicpc.net/problem/1753
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX
#define MAX_V 20001
using namespace std;

struct Edge {
    int v, w;
};

vector<Edge> adj[MAX_V];

int main(void) {
    int V, E, K;
    scanf("%d %d %d", &V, &E, &K);
    int u, v, w;
    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
    }

    int d[MAX_V];
    bool inQ[MAX_V];
    queue<int> Q;

    for(int i = 1; i <= V; i++) {
        d[i] = INF;
        inQ[i] = false;
    }

    d[K] = 0;
    Q.push(K);
    inQ[K] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inQ[u] = false;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (!inQ[v]) {
                    Q.push(v);
                    inQ[v] = true;
                }
            }
        }
    }

    for(int i = 1; i <= V; i++)
        if(d[i] >= INF)
            printf("INF\n");
        else
            printf("%d\n", d[i]);

    return 0;
}
