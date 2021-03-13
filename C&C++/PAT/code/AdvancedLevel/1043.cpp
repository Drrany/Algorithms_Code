// BST的先序遍历就是插入顺序
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

void construct1(node *&root, int key) {
    if (root == NULL) {
        root = new node(key);
        return;
    }
    if (key >= root->key) construct1(root->right, key);
    else construct1(root->left, key);
}

void construct2(node *&root, int key) {
    if (root == NULL) {
        root = new node(key);
        return;
    }
    if (key < root->key) construct2(root->right, key);
    else construct2(root->left, key);
}

void preTra(vector<int> &pre, node *root) {
    if (root == NULL) return;
    pre.push_back(root->key);
    preTra(pre, root->left);
    preTra(pre, root->right);
}

void postTra(vector<int> &post, node *root) {
    if (root == NULL) return;
    postTra(post, root->left);
    postTra(post, root->right);
    post.push_back(root->key);
}


int main() {
    int n, num;
    cin >> n;
    vector<int> pre;
    node *root1 = NULL, *root2 = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        pre.push_back(num);
        construct1(root1, num); // 普通树
        construct2(root2, num); // 镜像树
    }
    vector<int> pre1, pre2, post;
    preTra(pre1, root1);
    preTra(pre2, root2);

    if (pre == pre1) {
        cout << "YES\n";
        postTra(post, root1);
    } else if (pre == pre2) {
        cout << "YES\n";
        postTra(post, root2);
    } else {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << post[i];
        if (i < n - 1) cout << " ";
    }


}
