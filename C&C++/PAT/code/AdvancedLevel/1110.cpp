/*
 *  如何判断一棵树是否是完全二叉树：
 *      层序遍历，如果出现一个结点没有孩子，则其后遍历到的结点都不能有孩子，
 *      否则就不是完全二叉树。
 * */
#include <bits/stdc++.h>

using namespace std;

struct node {
    int left, right, ind;
};

int main() {
    int n;
    string l, r;
    cin >> n;
    vector<node> tree(n);
    vector<bool> isRoot(n, true);
    for (int i = 0; i < n; ++i) {
        tree[i].ind = i;
        cin >> l >> r;
        if (l != "-") {
            tree[i].left = stoi(l);
            isRoot[stoi(l)] = false;
        } else tree[i].left = -1;
        if (r != "-") {
            tree[i].right = stoi(r);
            isRoot[stoi(r)] = false;
        } else tree[i].right = -1;
    }
    int root;
    for (int i = 0; i < n; ++i) {
        if (isRoot[i]) root = i;
    }
    queue<node> q;
    node t;
    q.push(tree[root]);
    bool noChild = false, complete = true;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t.left != -1) {
            if (noChild)
                complete = false;
            else
                q.push(tree[t.left]);
        } else noChild = true;
        if (t.right != -1) {
            if (noChild)
                complete = false;
            else
                q.push(tree[t.right]);
        } else noChild = true;
    }
    if (complete)
        cout << "YES " << t.ind;
    else cout << "NO " << root;

}












