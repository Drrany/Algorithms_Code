#include <bits/stdc++.h>

using namespace std;
struct node {
    int w;
    vector<int> child;
};
int target, curW = 0;
vector<vector<int>> ans;
vector<int> cur;
vector<node> tree;

void dfs(int u) {
    if (tree[u].child.empty()) { // 到达叶结点
        if (curW == target)
            ans.push_back(cur);
        return;
    }
    vector<int> next = tree[u].child;
    for (const auto &e:next) {
        curW += tree[e].w;
        if (curW <= target) {
            cur.push_back(tree[e].w);
            dfs(e);
            cur.pop_back();
        }
        curW -= tree[e].w;
    }
}

bool cmp(const vector<int> &a, const vector<int> &b) {
    int len1 = a.size(), len2 = b.size();
    for (int i = 0; i < len1 && i < len2; ++i) {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return len1 > len2;
}

int main() {
    int n, m, id, num, ch;
    cin >> n >> m >> target;
    tree.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> tree[i].w;
    for (int i = 0; i < m; ++i) {
        cin >> id >> num;
        for (int j = 0; j < num; ++j) {
            cin >> ch;
            tree[id].child.push_back(ch);
        }
    }
    curW = tree[0].w;
    cur.push_back(tree[0].w);
    dfs(0);
    sort(ans.begin(), ans.end(), cmp);
    for (const auto &vi:ans) {
        int len = vi.size();
        for (int i = 0; i < len; ++i) {
            cout << vi[i];
            if (i < len - 1) cout << " ";
        }
        cout << "\n";
    }
}
