// 重做
/* 1. 二叉搜索树的中序遍历即为所有结点值从小到大排列
 * 2. 完全二叉树的第root个结点，左孩子为2*root，右孩子为2*root+1
 * 3. 中序遍历完全二叉树，按顺序填入结点值，即可得到层序遍历结果
 * */

#include <bits/stdc++.h>

using namespace std;
vector<int> ans;
int myIndex= 1;

void levelTar(int root, int n, const vector<int> &arr) {
    if (root > n) return;
    levelTar(root * 2, n, arr);
    ans[root] = arr[myIndex++];
    levelTar(root * 2 + 1, n, arr);
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    ans.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    levelTar(1, n, arr);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i];
        if (i < n) cout << " ";
    }
}