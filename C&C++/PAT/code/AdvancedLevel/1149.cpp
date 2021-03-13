#include <bits/stdc++.h>
// 用图存储内存超限的话，用邻接表替代
using namespace std;
unordered_map<int, unordered_set<int>> adj;

bool compatible(vector<int> &goods) {
    int len = goods.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int u = goods[i], v = goods[j];
            if (adj[u].find(v) != adj[u].end()) return false;
            if (adj[v].find(u) != adj[v].end()) return false;
        }
    }
    return true;
}

int main() {
    int n, m, u, v, k;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 0; i < m; ++i) {
        cin >> k;
        vector<int> goods;
        int g;
        for (int j = 0; j < k; ++j) {
            cin >> g;
            if (adj.find(g) != adj.end()) goods.push_back(g);
        }
        if (compatible(goods)) cout << "Yes\n";
        else cout << "No\n";
    }

}