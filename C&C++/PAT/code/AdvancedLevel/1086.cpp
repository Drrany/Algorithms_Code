#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *left, *right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

// pre: 1 2 3 4 5 6
// in: 3 2 4 1 5 6
node *construct(vector<int> pre, vector<int> in, int pl, int pr, int il, int ir) {
    if (pl > pr)
        return NULL;
    node *root = new node(pre[pl]);
    int index;
    for (int i = il; i <= ir; ++i) {
        if (in[i] == pre[pl]) {
            index = i;
            break;
        }
    }

    int lnum = index - il;
    int rnum = ir - index;

    root->left = construct(pre, in, pl + 1, pl + lnum, il, index - 1);
    root->right = construct(pre, in, pr - rnum + 1, pr, index + 1, ir);

    return root;
}

void postTra(vector<int> &post, node *root) {
    if (root == NULL)
        return;
    postTra(post, root->left);
    postTra(post, root->right);
    post.push_back(root->data);
}

int main() {
    int n, num;
    string f;
    stack<int> s;
    vector<int> pre, in;

    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> f;
        if (f == "Push") {
            cin >> num;
            s.push(num);
            pre.push_back(num);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }

    node *root = construct(pre, in, 0, n - 1, 0, n - 1);

    vector<int> post;
    postTra(post, root);

    for (int i = 0; i < n; ++i) {
        cout << post[i];
        if (i < n - 1)
            cout << " ";
    }

}