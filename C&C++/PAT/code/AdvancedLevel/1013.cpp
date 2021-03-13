#include <bits/stdc++.h>

using namespace std;

int G[1010][1010]{};
vector<bool> visited;

void dfs(int u, int n, int lost) {
    for (int i = 1; i <= n; ++i) {
        if (i != lost && !visited[i] && G[u][i] == 1) {
            visited[i] = true;
            dfs(i, n, lost);
        }
    }
}


int main() {
    int n, m, k, u, v, lost;
    cin >> n >> m >> k;
    visited.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    for (int i = 0; i < k; ++i) {
        cin >> lost;
        fill(visited.begin(), visited.end(), false);
        int count = 0;    // 剩下的连通分量
        for (int j = 1; j <= n; ++j) {
            if (j != lost && !visited[j]) {
                visited[j] = true;
                count++;
                dfs(j, n, lost);
            }
        }
        cout << count - 1 << endl;
    }
}