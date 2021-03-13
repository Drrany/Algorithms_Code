#include <bits/stdc++.h>
using namespace std;
int G[210][210]{};

int main() {
    int n, m, u, v, d, k, len;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> d;
        G[u][v] = G[v][u] = d;
    }
    cin >> k;
    int ans, ansDist = INT32_MAX;
    for (int i = 1; i <= k; ++i) {
        cin >> len;
        vector<int> city(len);
        int dis = 0;
        for (int j = 0; j < len; ++j)
            cin >> city[j];
        cout << "Path " << i << ": ";

        // 1. 相邻两点之间是否有路 f1
        vector<int> times(n + 1, 0);
        bool f1 = true, f2 = true;
        for (int j = 0; j < len; ++j) {
            times[city[j]]++;
            if (j > 0 && G[city[j - 1]][city[j]] == 0) f1 = false;
            else if (j > 0)dis += G[city[j - 1]][city[j]];
        }
        // 2. 是否遍历每个点，且起点终点相同 f2
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (times[j] == 0) f2 = false;
            if (times[j] == 1) count++;
        }
        if (city[0] != city[len - 1]) f2 = false;
        if (f1 && f2) { // 回路
            // 3. 是否是简单回路，即起始点恰好经过两次，其他点恰好经过一次
            if (times[city[0]] == 2 && count == n - 1)
                cout << dis << " (TS simple cycle)\n";
            else cout << dis << " (TS cycle)\n";
            if (dis < ansDist) {
                ansDist = dis;
                ans = i;
            }
        } else {
            if (f1) cout << dis << " (Not a TS cycle)\n";
            else cout << "NA (Not a TS cycle)\n";
        }
    }
    cout << "Shortest Dist(" << ans << ") = " << ansDist << "\n";
}