#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, id;
    cin >> n >> m;
    vector<vector<int>> tree(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        tree[id].resize(k);
        for (int j = 0; j < k; ++j)
            cin >> tree[id][j];
    }
    queue<int> q;
    q.push(1);
    int count = 1, next = 0, level = 1, ans = 1, ansLevel = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        count--;
        for (const auto &e:tree[t]) {
            q.push(e);
            next++;
        }
        if (count == 0) {
            level++;
            if (next > ans) {
                ans = next;
                ansLevel = level;
            }
            count = next;
            next = 0;
        }
    }
    cout << ans << " " << ansLevel;
}