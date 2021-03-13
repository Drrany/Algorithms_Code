#include <bits/stdc++.h>

using namespace std;

struct node {
    int left, right;
    int key;

    node() {
        left = -1, right = -1;
    }
};

node tree[110]{};
vector<int> arr;
int myIndex = 0;

// 中序遍历BST
void inTra(int root) {
    if (root == -1) return;
    inTra(tree[root].left);
    tree[root].key = arr[myIndex++];
    inTra(tree[root].right);
}

int main() {
    int n, l, r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        tree[i].left = l, tree[i].right = r;
    }

    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    inTra(0);

    // 层序遍历
    queue<int> q;
    q.push(0);
    int count = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << tree[t].key;
        if (++count < n) cout << " ";
        if (tree[t].left != -1) q.push(tree[t].left);
        if (tree[t].right != -1) q.push(tree[t].right);
    }
}