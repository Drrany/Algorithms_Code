#include <bits/stdc++.h>

using namespace std;
int mp[510]{};

int main() {
    int n, m, co;
    cin >> n >> m;
    vector<int> coins;
    for (int i = 0; i < n; ++i) {
        cin >> co;
        coins.push_back(co);
        mp[co]++;
    }
    sort(coins.begin(), coins.end());
    for (const auto &e:coins) {
        if ((m - e) >= 0 && (m - e) <= 510 && mp[m - e] > 0) {
            if (m == 2 * e && mp[e] == 1) continue;
            cout << e << " " << m - e;
            return 0;
        }
    }
    cout << "No Solution";


}
