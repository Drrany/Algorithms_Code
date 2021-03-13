#include <bits/stdc++.h>

using namespace std;

vector<int> ans, cur, coins;
int sum = 0, rest = 0, target;

void dfs(int n, int u) {
    if (!ans.empty()) return;
    if (u >= n) {
        if (sum == target)
            ans = cur;
        return;
    }
    rest -= coins[u];
    sum += coins[u];
    cur.push_back(coins[u]);
    if (sum <= target)
        dfs(n, u + 1);

    sum -= coins[u];
    cur.pop_back();
    if (sum + rest >= target)
        dfs(n, u + 1);
    rest += coins[u];
}

int main() {
    int n;
    cin >> n >> target;
    coins.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        rest += coins[i];
    }
    sort(coins.begin(), coins.end());
    dfs(n, 0);
    if (ans.empty()) cout << "No Solution";
    else {
        int len = ans.size();
        for (int i = 0; i < len; ++i) {
            cout << ans[i];
            if (i < len - 1) cout << " ";
        }
    }
}