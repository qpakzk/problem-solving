//https://www.acmicpc.net/problem/2150
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX_V 10001

using namespace std;

vector<vector<int> > G, GI, group;
int visited[MAX_V], g_num;;
stack<int> s;

void DFS(int v) {
    visited[v] = 1;

    for(int i = 0; i < G[v].size(); i++)
        if(visited[G[v][i]] == 0)
            DFS(G[v][i]);
    s.push(v);
}

void SCC(int v) {
    visited[v] = 1;
    group[g_num - 1].push_back(v);

    for(int i = 0; i < GI[v].size(); i++)
        if(visited[GI[v][i]] == 0)
            SCC(GI[v][i]);
}

bool comp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int main(void) {
    int V, E;
    scanf("%d %d", &V, &E);

    G.resize(V + 1);
    GI.resize(V + 1);
    for(int v = 1; v <= E; v++) {
        int A, B;
        scanf("%d %d", &A, &B);
        G[A].push_back(B);
        GI[B].push_back(A);
    }

    memset(visited, 0, sizeof(visited));
    for(int v = 1; v <= V; v++) {
        if(visited[v] == 0)
            DFS(v);
    }

    memset(visited, 0, sizeof(visited));
    while(!s.empty()) {
        int v = s.top();
        s.pop();

        if(visited[v] == 0) {
            g_num++;
            group.resize(g_num);
            SCC(v);
        }
    }

    for(int i = 0; i < g_num; i++)
        sort(group[i].begin(), group[i].end());
    sort(group.begin(), group.end(), comp);

    printf("%d\n", g_num);
    for(int i = 0; i < g_num; i++) {
        for(int j = 0; j < group[i].size(); j++)
            printf("%d ", group[i][j]);
        printf("-1\n");
    }

    return 0;
}
