// 重看 用图而不是树
#include <bits/stdc++.h>

using namespace std;

int G[1010][1010]{};
int n, l;

struct node {
    int index;
    int level;

    node(int i, int le) {
        index = i;
        level = le;
    }
};

int main() {
    cin >> n >> l;
    int k, f;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> f;
            G[i][f] = 1;  // i follow f
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> f;
        bool *visited = new bool[n + 1]{};
        int amount = 0;

        queue<node> q;
        q.push(node(f, 0));
        visited[f] = true;
        while (!q.empty()) {
            node t = q.front();
            q.pop();
            for (int j = 1; j <= n; ++j) {
                if (!visited[j] && t.level < l && G[j][t.index] == 1) {
                    visited[j] = true;
                    q.push(node(j, t.level + 1));
                    amount++;
                }
            }
        }
        cout << amount << endl;
    }
}