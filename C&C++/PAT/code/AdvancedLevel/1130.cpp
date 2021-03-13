#include <bits/stdc++.h>
using namespace std;

struct node {
    int left, right;
    string value;

    node() {}

    node(string v, int l, int r) {
        left = l, right = r;
        value = v;
    }
};

vector<node> tree;
int ori;

void inTra(int root) {
    if (root == -1) return;
    if (root != ori && (tree[root].left != -1 || tree[root].right != -1))
        cout << "(";
    inTra(tree[root].left);
    cout << tree[root].value;
    inTra(tree[root].right);
    if (root != ori && (tree[root].left != -1 || tree[root].right != -1))
        cout << ")";
}

int main() {
    int n, l, r;
    cin >> n;
    tree.resize(n + 1);
    vector<bool> isRoot(n + 1, true);
    string value;
    for (int i = 1; i <= n; ++i) {
        cin >> value >> l >> r;
        if (l != -1) isRoot[l] = false;
        if (r != -1) isRoot[r] = false;
        tree[i] = node(value, l, r);
    }
    for (int i = 1; i <= n; ++i) {
        if (isRoot[i]) {
            ori = i;
            break;
        }
    }
    inTra(ori);
}