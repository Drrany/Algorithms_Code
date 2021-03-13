#include <bits/stdc++.h>
using namespace std;
int G[1010][1010]{};

int main() {
    int n, m, u, v, k;
    cin >> n >> m;
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        inDegree[v]++;
        G[u][v] = 1;
    }
    cin >> k;
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
        bool flag = true;
        vector<int> tmp(inDegree);
        for (int j = 0; j < n; ++j) {
            cin >> u;
            if (flag) {
                // 判断u的入度是否为0
                if (tmp[u] == 0) {
                    // 将从u出发的边去掉
                    for (int l = 1; l <= n; ++l) {
                        if (G[u][l] == 1) tmp[l]--;
                    }
                } else flag = false;
            }
        }
        if (!flag) ans.push_back(i);
    }
    int len = ans.size();
    for (int i = 0; i < len; ++i) {
        cout << ans[i];
        if (i < len - 1) cout << " ";
    }
}