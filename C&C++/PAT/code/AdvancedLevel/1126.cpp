#include <bits/stdc++.h>

using namespace std;

/*
 * Eulerian：有欧拉回路（连通图，所有顶点的度都是偶数）
 * semi-Eulerian：有欧拉路径，无欧拉回路（恰有两个顶点的度是奇数）
 * */

int G[510][510]{};

void dfs(vector<bool> &visited, int u, int n) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && G[u][i] == 1) {
            visited[i] = true;
            dfs(visited, i, n);
        }
    }
}

int main() {

    int n, m, u, v;
    cin >> n >> m;
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        cout << degree[i];
        if (i < n) cout << " ";
    }
    cout << "\n";
    // 判断是否是连通图
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    dfs(visited, 1, n);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "Non-Eulerian";
            return 0;
        }
    }
    // 判断入度的奇偶数
    int odd = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 == 1) odd++;
    }
    if (odd == 0) cout << "Eulerian";
    else if (odd == 2) cout << "Semi-Eulerian";
    else cout << "Non-Eulerian";

}