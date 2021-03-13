#include <bits/stdc++.h>
using namespace std;

struct node {
    node *left, *right;
    int key;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

vector<int> pre, in, post;

/*
 * pre: 1 2 3 4 5 6 7
 * in : 2 3 1 5 4 7 6
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

void postTra(node *root) {
    if (root == NULL) return;
    postTra(root->left);
    postTra(root->right);
    post.push_back(root->key);
}

int main() {
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    node *root = construct(0, n - 1, 0, n - 1);
    postTra(root);
    cout << post[0];
}