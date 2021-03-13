#include <bits/stdc++.h>
using namespace std;
/*
 * 1. 用map存储出现过的结点，不要遍历查找结点，节约时间
 * 2. 如何找公共最小祖先！！
 * */
struct node {
    node *left, *right;
    int key;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

vector<int> pre, in;

/*
 * pre: 6 3 1 2 5 4 8 7
 * in:  1 2 3 4 5 6 7 8
 * */
node *construct(int pl, int pr, int il, int ir) {
    if (pl > pr) return NULL;
    node *root = new node(pre[pl]);
    int mid = il;
    while (mid <= ir && in[mid] != pre[pl]) mid++;
    root->left = construct(pl + 1, pl + mid - il, il, mid - 1);
    root->right = construct(pl + mid - il + 1, pr, mid + 1, ir);
    return root;
}


void findLCA(node *root, int u, int v) {
    if (root == NULL) return;
    if (root->key == u) cout << u << " is an ancestor of " << v << ".\n";
    else if (root->key == v) cout << v << " is an ancestor of " << u << ".\n";
    else if (u < root->key && v < root->key) findLCA(root->left, u, v);
    else if (u >= root->key && v >= root->key) findLCA(root->right, u, v);
    else cout << "LCA of " << u << " and " << v << " is " << root->key << ".\n";
}

int main() {
    int m, n, key;
    cin >> m >> n;
    unordered_map<int, bool> mp;
    for (int i = 0; i < n; ++i) {
        cin >> key;
        mp[key] = true;
        in.push_back(key);
        pre.push_back(key);
    }
    sort(in.begin(), in.end());
    node *root = construct(0, n - 1, 0, n - 1);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        if (!mp[u] && !mp[v]) cout << "ERROR: " << u << " and " << v << " are not found.\n";
        else if (!mp[u]) cout << "ERROR: " << u << " is not found.\n";
        else if (!mp[v]) cout << "ERROR: " << v << " is not found.\n";
        else findLCA(root, u, v);
    }

}