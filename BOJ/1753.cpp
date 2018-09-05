//https://www.acmicpc.net/problem/1753
#include <iostream>
#include <list>
#include <queue>

#define INF 99999

using namespace std;

int V, E, K;
vector<list<pair<int, int>>> G;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist;

void dijkstra() {

    dist.assign(V + 1, INF);
    pq.push(make_pair(0, K));
    dist[K] = 0;


    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(list<pair<int, int>>::iterator it = G[u].begin(); it != G[u].end(); it++) {
            int v = it->first;
            int w = it->second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main(void) {
    cin >> V >> E >> K;

    G.resize(V + 1);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
    }
    dijkstra();

    for(int i = 1; i <= V; i++)
        if(dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;

    return 0;
}
