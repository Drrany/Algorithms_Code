#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, num;
    cin >> n;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
    cin >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        int inter = abs(sum[u - 1] - sum[v - 1]);
        int outer = sum[n] - inter;
        cout << min(inter, outer) << "\n";
    }

}
