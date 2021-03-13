#include <bits/stdc++.h>

using namespace std;

struct node {
    int len;
    vector<int> child;

    node(int k) {
        len = k;
    }
};

int main() {
    int n, m, k, id, t;
    cin >> n >> m;
    vector<node> tree;
    for (int i = 0; i <= n; ++i)
        tree.emplace_back(0);
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        tree[id].len = k;
        for (int j = 0; j < k; ++j) {
            cin >> t;
            tree[id].child.push_back(t);
        }
    }
    // 层序遍历
    queue<int> q;
    vector<int> ans, tmp;
    int count = 1, next = 0, len, curAns = 0;
    q.push(1);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        count--;
        if (tree[t].len == 0) curAns++;
        else {
            next += tree[t].len;
            for (const auto &e:tree[t].child)
                q.push(e);
        }
        if (count == 0) {
            ans.push_back(curAns);
            curAns = 0;
            count = next;
            next = 0;
        }
    }
    len = ans.size();
    for (int i = 0; i < len; ++i) {
        cout << ans[i];
        if (i < len - 1) cout << " ";
    }
}