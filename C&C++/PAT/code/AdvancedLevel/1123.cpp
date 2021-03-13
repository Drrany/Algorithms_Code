/*
    再做一遍！！！
    
 * AVL树：
 *      1. 因为不能通过当前结点的子树的平衡因子计算得到该结点的平衡因子，所以记录每个结点的高度来间接获得，叶子结点的高度初始化为1
 *      2. 记住LL、LR、RR、RL分别如何旋转调整
 * 判断是不是完全二叉树，就看在出现了一个孩子为空的结点之后是否还会出现孩子结点不为空的结点，如果出现了就不是完全二叉树。
 * */

#include <bits/stdc++.h>

#include <bits/stdc++.h>
// 1109
using namespace std;

struct node {
    node *left, *right;
    int key;

    node(int k) {
        key = k;
        left = right = NULL;
    }
};

// 计算root的高度
int getHeight(node *root) {
    if (root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

// 得到root的平衡因子
int getBalanced(node *root) {
    return getHeight(root->left) - getHeight(root->right);
}

void R(node *&root) {
    node *left = root->left;
    root->left = left->right;
    left->right = root;
    root = left;
}

void L(node *&root) {
    node *right = root->right;
    root->right = right->left;
    right->left = root;
    root = right;
}

void construct(node *&root, int key) {
    if (root == NULL)
        root = new node(key);
    else if (key <= root->key) {
        construct(root->left, key);
        int ba = getBalanced(root);
        if (ba == 2) {
            int ne = getBalanced(root->left);
            if (ne == 1) { // LL型
                R(root);
            } else if (ne == -1) { // LR型
                L(root->left);
                R(root);
            }
        }

    } else {
        construct(root->right, key);
        int ba = getBalanced(root);
        if (ba == -2) {
            int ne = getBalanced(root->right);
            if (ne == -1) { // RR型
                L(root);
            } else if (ne == 1) { // RL型
                R(root->right);
                L(root);
            }
        }
    }

}

int main() {
    int n, num;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        construct(root, num);
    }
    queue<node *> q;
    q.push(root);
    bool noChild = false, complete = true;
    vector<int> ans;
    while (!q.empty()) {
        node *t = q.front();
        ans.push_back(t->key);
        q.pop();
        if (t->left != NULL) {
            if (noChild) complete = false;
            q.push(t->left);
        } else noChild = true;
        if (t->right != NULL) {
            if (noChild) complete = false;
            q.push(t->right);
        } else noChild = true;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if (i < n - 1) cout << " ";
    }
    if (complete) cout << "\nYES";
    else cout << "\nNO";
}