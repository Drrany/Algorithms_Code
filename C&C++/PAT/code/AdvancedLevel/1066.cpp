// 构建二叉平衡树 重做
#include <bits/stdc++.h>

using namespace std;

struct node {
    node *left, *right;
    int value;

    node(int v) {
        value = v;
        left = right = NULL;
    }
};

// 右旋
void R(node *&root) {
    node *left = root->left;
    root->left = left->right;
    left->right = root;
    root = left;
}

// 左旋
void L(node *&root) {
    node *right = root->right;
    root->right = right->left;
    right->left = root;
    root = right;
}

int getHeight(node *root) {
    if (root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalance(node *root) {
    return getHeight(root->left) - getHeight(root->right);
}

void construct(node *&root, int value) {
    if (root == NULL) {
        root = new node(value);
        return;
    } else if (value < root->value) { // 在左侧插入
        construct(root->left, value);
        int cur = getBalance(root);
        if (cur == 2) { // L型
            int left = getBalance(root->left);
            if (left == 1) // LL型
                R(root);
            else if (left == -1) { // LR型
                L(root->left);
                R(root);
            }
        }

    } else {
        construct(root->right, value);
        int cur = getBalance(root);
        if (cur == -2) { // R型
            int right = getBalance(root->right);
            if (right == -1) // RR型
                L(root);
            else if (right == 1) { // RL型
                R(root->right);
                L(root);
            }
        }
    }
}


int main() {
    int n, value;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        construct(root, value);

    }
    cout << root->value;
}