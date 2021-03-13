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

void inOrder(vector<int> &in, node *root) {
    if (root == NULL)
        return;
    inOrder(in, root->left);
    in.push_back(root->data);
    inOrder(in, root->right);
}


int main() {
    int n;
    cin >> n;
    vector<node *> nodes;
    for (int i = 0; i < n; ++i) {
        node *t = new node(i);
        nodes.push_back(t);
    }
    string a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a != "-")
            nodes[i]->right = nodes[stoi(a)];
        if (b != "-")
            nodes[i]->left = nodes[stoi(b)];
    }

    // 找根节点
    node *root;
    vector<int> in;
    for (int i = 0; i < n; ++i) {
        in.clear();
        root = nodes[i];
        inOrder(in, root);
        if (in.size() == n)
            break;
    }

    // 层序遍历
    vector<int> level;
    queue<int> q;
    q.push(root->data);
    while (!q.empty()) {
        int index = q.front();
        level.push_back(index);
        q.pop();

        if (nodes[index]->left != NULL)
            q.push(nodes[index]->left->data);
        if (nodes[index]->right != NULL)
            q.push(nodes[index]->right->data);
    }


    for (int i = 0; i < n; ++i) {
        cout << level[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << in[i];
        if (i < n - 1)
            cout << " ";
    }


}