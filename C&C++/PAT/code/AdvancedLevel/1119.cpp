/* 如何确定是否唯一？？？
 * 已知二叉树的前序和后序是无法唯一确定一颗二叉树的，因为可能会存在
 * 多种情况，这种情况就是一个结点可能是根的左孩子也有可能是根的右孩子，
 * 只要父亲节点只包含一个子节点，那么这个答案就是不唯一的。
 * 如果发现了一个无法确定的状态，可以假定这个不可确定的孩子的状态是右孩子
 *
 * 如何求根结点和左右孩子划分：
 *      先序遍历： 1 2 3 4 6 7 5       后序遍历： 2 6 7 4 5 3 1
 *      在先序遍历中先取出开始的节点1，这个节点定为当前根节点，1后面一个
 *      节点2一定是节点1的一个子节点，然后在后序遍历中寻找节点2，于是便
 *      可知节点2（包括2）之前的位于节点1的左子树中，2（不包括2）后面的
 *      节点直至节点1，位于节点1的右子树
 *      节点3 4 6 7 5位于节点1的右子树中，3为这个子树的根节点，节点4为
 *      节点3的左或右子节点中的一个，后序遍历中找到节点4，可以知道节点
 *      6 7 4位于节点3的左子树中，节点5位于节点3的右子树中
 *      依次类推，可以遍历完这棵树，于是便可得到中序遍历
 * */
#include <bits/stdc++.h>

using namespace std;

struct node {
    node *left, *right;
    int key;

    node(int k) {
        left = right = NULL;
        key = k;
    }
};

bool flag = true;

node *construct(const vector<int> &pre, const vector<int> &post, int prl, int prr, int ptl, int ptr) {
    if (prl > prr) return NULL;
    // 前序的第一个和后序的最后一个相等，是根节点
    node *root = new node(pre[prl]);
    // 如果只有一个子节点，说明不唯一，默认安排为右子树
    if (prr - prl == 1) {
        flag = false;
        root->right = construct(pre, post, prl + 1, prr, ptl, ptr - 1);
    } else if (prr - prl > 1) {
        // 查找前序的下一个结点在后序中的位置
        int target = pre[prl + 1], i = ptl;
        for (; i <= ptr; ++i) {
            if (post[i] == target)
                break;
        }
        // 以这个位置划分左右子树
        root->left = construct(pre, post, prl + 1, prl + i - ptl + 1, ptl, i);
        root->right = construct(pre, post, prl + i - ptl + 2, prr, i + 1, ptr - 1);
    }
    return root;
}

int cnt = 0;

void inOrder(node *&root, int n) {
    if (root == NULL) return;
    inOrder(root->left, n);
    cout << root->key;
    cnt++;
    if (cnt < n) cout << " ";
    inOrder(root->right, n);
}

int main() {
    int n;
    cin >> n;
    vector<int> pre(n), post(n);
    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    for (int i = 0; i < n; ++i)
        cin >> post[i];
    node *root = construct(pre, post, 0, n - 1, 0, n - 1);
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    inOrder(root, n);
    cout << "\n";
}

