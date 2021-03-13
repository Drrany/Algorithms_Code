#include <bits/stdc++.h>
// 重看
using namespace std;
const int maxn = 10010;
unordered_set<int> G[maxn]{};

int main() {
    int n, m, u, v, k, len;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        G[u].insert(v);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> len;
        unordered_set<int> ver;
        for (int j = 0; j < len; ++j) {
            cin >> v;
            ver.insert(v);
        }
        bool flag = true;
        for (int j = 0; j < n && flag; ++j) {
            // 如果j有相邻顶点且j不在点集中
            if (!G[j].empty() && ver.count(j) == 0) {
                for (const auto &e:G[j]) {
                    if (ver.count(e) == 0) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }

}