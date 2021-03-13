#include <bits/stdc++.h>
using namespace std;
vector<int> in, post;

struct node {
    node *left, *right;
    int key;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

/*
 * in:   12 11 20 17 1 15 8 5
 * post: 12 20 17 11 15 8 5 1
 * */
node *construct(int il, int ir, int pl, int pr) {
    if (il > ir) return NULL;
    node *root = new node(post[pr]);
    int mid = il;
    while (mid <= ir && in[mid] != post[pr]) mid++;
    root->left = construct(il, mid - 1, pl, pl + mid - il - 1);
    root->right = construct(mid + 1, ir, pl + mid - il, pr - 1);
    return root;
}

int main() {
    int n;
    cin >> n;
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    for (int i = 0; i < n; ++i)
        cin >> post[i];
    node *root = construct(0, n - 1, 0, n - 1);

    queue<node *> q;
    q.push(root);
    int flag = -1, count = 1, next = 0;
    vector<int> ans, cur;
    while (!q.empty()) {
        node *t = q.front();
        cur.push_back(t->key);
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
            count = next;
            next = 0;
            if (flag == 1)
                ans.insert(ans.end(), cur.begin(), cur.end());
            else ans.insert(ans.end(), cur.rbegin(), cur.rend());
            cur.clear();
            flag = -flag;
        }
    }
    int len = ans.size();
    for (int i = 0; i < len; ++i) {
        cout << ans[i];
        if (i < len - 1) cout << " ";
    }
}