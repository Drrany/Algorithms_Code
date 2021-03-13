#include <bits/stdc++.h>

using namespace std;

struct node {
    vector<int> child;
    int num;
};

int ansLen = INT32_MAX;
int ansNum;
double p, r;

void dfs(vector<node> &tree, int u, int len) {
    if (len > ansLen) return;
    if (tree[u].num == 0) { // 到达子节点
        if (len == ansLen) ansNum++;
        else if (len < ansLen) {
            ansNum = 1;
            ansLen = len;
        }
        return;
    }
    vector<int> cd = tree[u].child;
    for (int i = 0; i < tree[u].num; ++i) {
        dfs(tree, cd[i], len + 1);
    }
}

int main() {
    int n, k, c;
    cin >> n >> p >> r;
    vector<node> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        tree[i].num = k;
        for (int j = 0; j < k; ++j) {
            cin >> c;
            tree[i].child.push_back(c);
        }
    }
    dfs(tree, 0, 0);
    double ansPro = pow((1.0 + 0.01 * r), ansLen) * p;
    printf("%.4f %d", ansPro, ansNum);

}












