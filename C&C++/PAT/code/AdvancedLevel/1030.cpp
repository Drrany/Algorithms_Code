#include <bits/stdc++.h>

using namespace std;
int G1[510][510]{};
int G2[510][510]{};

int main() {
    int n, m, src, dst, u, v, d, c;
    cin >> n >> m >> src >> dst;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> d >> c;
        G1[u][v] = G1[v][u] = d;
        G2[u][v] = G2[v][u] = c;
    }

    vector<bool> visited(n, false);
    vector<int> dist(n, INT32_MAX);
    vector<int> cost(n, INT32_MAX);
    vector<int> pre(n);
    dist[src] = 0, cost[src] = 0;
    for (int i = 0; i < n; ++i) {
        int tg = -1, minDt = INT32_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDt) {
                minDt = dist[j];
                tg = j;
            }
        }
        visited[tg] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && G1[tg][j] != 0) {
                int newDt = dist[tg] + G1[tg][j];
                int newCt = cost[tg] + G2[tg][j];
                if (newDt < dist[j]) {
                    dist[j] = newDt, cost[j] = newCt;
                    pre[j] = tg;
                } else if (newDt == dist[j] && newCt < cost[j]) {
                    cost[j] = newCt;
                    pre[j] = tg;
                }
            }
        }
    }

    int p = dst;
    vector<int> path;
    while (p != src) {
        path.push_back(p);
        p = pre[p];
    }
    path.push_back(src);
    for (auto it = path.rbegin(); it != path.rend(); it++)
        cout << *it << " ";
    cout << dist[dst] << " " << cost[dst];

}