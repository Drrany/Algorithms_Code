#include <bits/stdc++.h>
// 如何计算结点的高度
using namespace std;

struct node {
    node *left, *right;
    int value;
    int black;

    node(int v) {
        left = right = NULL;
        value = v;
        if (value > 0) black = 1;
        else black = 0;
    }
};

/*
 * pre: 7 -2 1 5 -4 -11 8 14 -15
 * in:  1 -2 -4 5 7 8 -11 14 -15
 * */
node *construct(const vector<int> &pre, const vector<int> &in, int pl, int pr, int il, int ir) {
    if (pl > pr) return NULL;
    node *root = new node(pre[pl]);
    int mid = il;
    while (mid <= ir && abs(in[mid]) != abs(pre[pl]))
        mid++;
    root->left = construct(pre, in, pl + 1, pl + mid - il, il, mid - 1);
    root->right = construct(pre, in, pl + mid - il + 1, pr, mid + 1, ir);
    return root;
}

bool cmp(int a, int b) {
    return abs(a) < abs(b);
}

bool judge1(node *root) {
    if (root == NULL) return true;
    if (root->black == 0) { // 红色结点
        if (root->left != NULL && root->left->black == 0) return false;
        if (root->right != NULL && root->right->black == 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}

int getHei(node *root) {
    if (root == NULL) return 0;
    int lf = getHei(root->left);
    int rg = getHei(root->right);
    return root->black ? max(lf, rg) + 1 : max(lf, rg);
}

bool judge2(node *root) {
    if (root == NULL) return true;
    int lf = getHei(root->left);
    int rg = getHei(root->right);
    if (lf != rg) return false;
    return judge2(root->left) && judge2(root->right);
}

int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n;
        vector<int> pre(n), in(n);
        for (int j = 0; j < n; ++j) {
            cin >> pre[j];
            in[j] = pre[j];
        }
        sort(in.begin(), in.end(), cmp);
        node *root = construct(pre, in, 0, n - 1, 0, n - 1);
        // 1. 根节点不是黑色
        if (root->black == 0) {
            cout << "No\n";
            continue;
        }
        // 2. 红色结点的孩子不都是黑色
        if (!judge1(root)) {
            cout << "No\n";
            continue;
        }
        // 3. 每个节点到它的每个叶结点，没有经过相同数目的黑色节点
        if (!judge2(root)) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
}