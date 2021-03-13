#include <bits/stdc++.h>

using namespace std;
int G[210][210]{};

bool isClique(const vector<int> &ver, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (G[ver[j]][ver[i]] != 1) return false;
        }
    }
    return true;
}

bool haveVer(const vector<int> &ver, int len, int v) {
    for (int i = 0; i < len; ++i) {
        if (ver[i] == v) return true;
    }
    return false;
}

int main() {
    int nv, ne, u, v, m, len;
    cin >> nv >> ne;
    for (int i = 0; i < ne; ++i) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> len;
        vector<int> ver(len);
        for (int j = 0; j < len; ++j)
            cin >> ver[j];
        if (isClique(ver, len)) {
            bool moreCl = false;
            for (int j = 1; j <= nv && !moreCl; ++j) {
                if (!haveVer(ver, len, j)) {
                    ver.push_back(j);
                    if (isClique(ver, len + 1)) {
                        cout << "Not Maximal\n";
                        moreCl = true;
                    }
                    ver.pop_back();
                }
            }
            if (!moreCl)
                cout << "Yes\n";
        } else cout << "Not a Clique\n";
    }


}