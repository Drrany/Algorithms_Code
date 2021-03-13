#include <bits/stdc++.h>

using namespace std;

struct node {
    int key;
    node *left, *right;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

node *construct(const vector<int> &post, const vector<int> &in, int pl, int pr, int il, int ir) {
    if (pl > pr) return NULL;
    int key = post[pr], i = il;
    node *root = new node(key);
    for (; i <= ir; ++i) {
        if (in[i] == key)
            break;
    }
    int count = i - il;
    root->left = construct(post, in, pl, pl + count - 1, il, i - 1);
    root->right = construct(post, in, pl + count, pr - 1, i + 1, ir);
    return root;
}

int main() {
    int n, m = 0;
    cin >> n;
    vector<int> post(n), in(n);
    for (int i = 0; i < n; ++i)
        cin >> post[i];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    node *root = construct(post, in, 0, n - 1, 0, n - 1);
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *t = q.front();
        q.pop();
        cout << t->key;
        if (++m < n)
            cout << " ";
        if (t->left != NULL) q.push(t->left);
        if (t->right != NULL) q.push(t->right);
    }
}