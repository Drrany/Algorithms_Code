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

void construct(int key, node *&root) {
    if (root == NULL)
        root = new node(key);
    else if (key <= root->key)
        construct(key, root->left);
    else construct(key, root->right);
}

int main() {
    int n, num;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        construct(num, root);
    }
    queue<node *> q;
    q.push(root);
    int count = 1, next = 0, level = 0;
    vector<int> ans;
    ans.push_back(count);
    while (!q.empty()) {
        node *t = q.front();
        q.pop();
        count--;
        if (t->left != NULL) {
            q.push(t->left);
            next++;
        }
        if (t->right != NULL) {
            q.push(t->right);
            next++;
        }
        if (count == 0) {
            ans.push_back(next);
            level++;
            count = next;
            next = 0;
        }
    }
    int n1 = (level - 1) >= 0 ? ans[level - 1] : 0;
    int n2 = (level - 2) >= 0 ? ans[level - 2] : 0;
    cout << n1 << " + " << n2 << " = " << n1 + n2;
}