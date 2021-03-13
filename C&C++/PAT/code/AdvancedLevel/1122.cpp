#include <bits/stdc++.h>

using namespace std;

int G[210][210]{};

int main() {
    int n, m, u, v, k, len;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> len;
        bool flag = true;
        vector<int> ver(len);
        cin >> ver[0];
        unordered_set<int> vis;
        for (int j = 1; j < len; ++j) {
            cin >> ver[j];
            if (vis.find(ver[j]) != vis.end() || (G[ver[j]][ver[j - 1]] == 0)) // 该顶点已出现过或无路径
                flag = false;
            else vis.insert(ver[j]);
        }

        if (flag && (ver[0] == ver[len - 1]) && len == n + 1) cout << "YES\n";
        else cout << "NO\n";
    }
}

