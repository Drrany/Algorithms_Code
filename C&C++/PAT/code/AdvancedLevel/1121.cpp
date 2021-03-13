#include <bits/stdc++.h>
// 重看
using namespace std;

int G[100000]{};

int main() {
    int n, m, a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        G[a] = b;
        G[b] = a;
    }
    cin >> m;
    unordered_set<int> guest;
    vector<int> sg;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        guest.insert(a);
    }
    for (const auto &e:guest) {
        if (guest.count(G[e]) == 0) sg.push_back(e);
    }
    int len = sg.size();
    cout << len << endl;
    if (len > 0) {
        sort(sg.begin(), sg.end());
        for (int i = 0; i < len; ++i) {
            printf("%05d", sg[i]);
            if (i < len - 1) cout << " ";
        }
    }
}

