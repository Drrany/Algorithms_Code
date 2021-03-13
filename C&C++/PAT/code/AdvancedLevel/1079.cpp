#include <bits/stdc++.h>

using namespace std;
struct node {
    int amount;
    vector<int> child;
};
double price, myRate, ans = 0;

void dfs(int u, int level, vector<node> &tree) {
    if (tree[u].child.empty()) { // 零售商
        double times = pow((1 + 0.01 * myRate), level);
        ans += times * price * tree[u].amount;
        return;
    }
    vector<int> next = tree[u].child;
    for (const auto &e:next)
        dfs(e, level + 1, tree);

}

int main() {
    int n, k;
    cin >> n >> price >> myRate;
    vector<node> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (k == 0) cin >> tree[i].amount;
        else {
            tree[i].child.resize(k);
            for (int j = 0; j < k; ++j)
                cin >> tree[i].child[j];
        }
    }
    dfs(0, 0, tree);
    printf("%.1f", ans);
}