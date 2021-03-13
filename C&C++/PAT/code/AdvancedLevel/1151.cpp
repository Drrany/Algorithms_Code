#include <bits/stdc++.h>
// 重做 如何找普通二叉树的LCA
using namespace std;

struct Node {
    Node *left, *right;
    int value;

    Node(int v) {
        value = v;
        left = right = NULL;
    }
};

// 1. 不将in、pre传参进去，执行时间大幅度增加
// 2. 使用传参建树而不是return，速度也会增加
vector<int> in, pre;

void construct(Node *&root, int il, int ir, int pl, int pr) {
    if (il > ir) return;
    root = new Node(pre[pl]);
    // 在in中找到pre[pl]的位置
    int i;
    for (i = il; i <= ir; ++i) {
        if (in[i] == pre[pl])
            break;
    }
    construct(root->left, il, i - 1, pl + 1, pl + i - il);
    construct(root->right, i + 1, ir, pl + i - il + 1, pr);
}

// 找a、b的LCA的核心代码
Node *searchLCA(int a, int b, Node *root) {
    if (root == NULL) return NULL;
    if (root->value == a || root->value == b) return root;
    Node *l = searchLCA(a, b, root->left);
    Node *r = searchLCA(a, b, root->right);
    if (l != NULL && r != NULL) return root;
    return l == NULL ? r : l;
}

int main() {
    int m, n;
    cin >> m >> n;
    int num;
    unordered_set<int> all;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        all.insert(num);
        in.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        cin >> num;
        pre.push_back(num);
    }
    Node *root = NULL;
    construct(root, 0, n - 1, 0, n - 1);

    // m个查询
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        bool hasA = !(all.find(a) == all.end());
        bool hasB = !(all.find(b) == all.end());
        if (!hasA && !hasB)
            cout << "ERROR: " << a << " and " << b << " are not found.\n";
        else if (!hasA)
            cout << "ERROR: " << a << " is not found.\n";
        else if (!hasB)
            cout << "ERROR: " << b << " is not found.\n";
        else {
            int lca = searchLCA(a, b, root)->value;
            if (lca == a)
                cout << a << " is an ancestor of " << b << ".\n";
            else if (lca == b)
                cout << b << " is an ancestor of " << a << ".\n";
            else cout << "LCA of " << a << " and " << b << " is " << lca << ".\n";
        }
    }

}