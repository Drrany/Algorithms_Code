// 方法1：迪杰斯特拉
#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 510;
int G[MAXSIZE][MAXSIZE]{};

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;

    int *teams = new int[n];
    int *wt = new int[n]{};
    for (int i = 0; i < n; ++i)
        cin >> teams[i];
    wt[s] = teams[s];

    int a, b, num;
    fill(G[0], G[0] + MAXSIZE * MAXSIZE, INT32_MAX);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> num;
        G[a][b] = G[b][a] = num;
    }

    bool *visited = new bool[n]{};
    int *dist = new int[n];
    int *paths = new int[n]{};
    fill(dist, dist + n, INT32_MAX);
    dist[s] = 0, paths[s] = 1;

    for (int i = 0; i < n; ++i) {
        // 在未访问的城市中找距离s最近的
        int mp = INT32_MAX, u = -1;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] < mp) {
                mp = dist[v];
                u = v;
            }
        }
        if (u == -1) return 0;// 不连通
        visited[u] = true;
        // 更新
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && G[u][v] < INT32_MAX) {
                if (mp + G[u][v] < dist[v]) {
                    dist[v] = mp + G[u][v];
                    paths[v] = paths[u];
                    wt[v] = wt[u] + teams[v];
                } else if (mp + G[u][v] == dist[v]) {
                    paths[v] += paths[u];
                    wt[v] = max(wt[v], wt[u] + teams[v]);
                }
            }
        }
    }
    cout << paths[d] << " " << wt[d];
}

// 方法2：迪杰斯特拉+DFS
#include <bits/stdc++.h>

using namespace std;
int G[510][510]{};
int maxNum = 0, ansPath = 0, ansNum = 0;
int src, dst;
vector<int> rescue;
vector<bool> visited;

void dfs(int u, int path, int num, int n) {
    if (u == dst) {
        if (path == ansPath) {
            ansNum++;
            maxNum = max(maxNum, num);
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && G[u][i] > 0) {
            visited[i] = true;
            dfs(i, path + G[u][i], num + rescue[i], n);
            visited[i] = false;
        }
    }
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m >> src >> dst;
    rescue.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> rescue[i];
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }

    visited.resize(n, false);
    vector<int> dist(n, INT32_MAX);
    dist[src] = 0;
    for (int i = 0; i < n; ++i) {
        // 找最近的
        int t = -1, minDt = INT32_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDt) {
                minDt = dist[j];
                t = j;
            }
        }
        visited[t] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && G[t][j] > 0)
                dist[j] = min(dist[j], dist[t] + G[t][j]);
        }
    }
    ansPath = dist[dst];
    fill(visited.begin(), visited.end(), false);
    visited[src] = true;
    dfs(src, 0, rescue[src], n);
    cout << ansNum << " " << maxNum;
}