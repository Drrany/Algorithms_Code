#include <bits/stdc++.h>

using namespace std;

struct node {
    int depth;
    vector<int> child;
};

int maxDepth = 0;

void tra(vector<node *> &tree, int root, int depth) {
    maxDepth = max(maxDepth, depth);
    tree[root]->depth = depth;
    vector<int> c = tree[root]->child;
    for (int i = 0; i < c.size(); ++i)
        tra(tree, c[i], depth + 1);
}

int main() {
    int n;
    double p, r;
    cin >> n >> p >> r;
    r = 1.0 + r * 0.01;
    vector<node *> tree;
    for (int i = 0; i < n; ++i) {
        node *t = new node();
        tree.push_back(t);
    }
    int root;
    for (int i = 0; i < n; ++i) {
        int parent;
        cin >> parent;
        if (parent == -1)
            root = i;
        else
            tree[parent]->child.push_back(i);
    }

    tra(tree, root, 0);
    int ansCount = 0;
    for (int i = 0; i < n; ++i) {
        if (tree[i]->depth == maxDepth)
            ansCount++;
    }
    double ans = p * pow(r, maxDepth);
    printf("%.2f %d", ans, ansCount);
}