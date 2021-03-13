// 对于一颗数组存储的完全二叉树，下标从1开始
// 第i个结点的左子树为第2*i个结点，右子树为第2*i+1个结点
#include <bits/stdc++.h>
using namespace std;
vector<int> cur, arr;

void tra(int i, int n) {
    cur.push_back(arr[i]);
    if (2 * i > n) { // 第i个结点为叶结点
        int len = cur.size();
        for (int j = 0; j < len; ++j) {
            cout << cur[j];
            if (j < len - 1) cout << " ";
        }
        cout << "\n";
        cur.pop_back();
        return;
    }
    if ((2 * i + 1) <= n) tra(2 * i + 1, n);
    tra(2 * i, n);
    cur.pop_back();
}

bool isMaxHeap(int n) {
    for (int i = 1; 2 * i <= n; ++i) {
        if (arr[i] < arr[2 * i]) return false;
        if ((2 * i + 1) <= n && arr[i] < arr[2 * i + 1]) return false;
    }
    return true;
}

bool isMinHeap(int n) {
    for (int i = 1; 2 * i <= n; ++i) {
        if (arr[i] > arr[2 * i]) return false;
        if ((2 * i + 1) <= n && arr[i] > arr[2 * i + 1]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    tra(1, n);
    if (isMaxHeap(n)) cout << "Max Heap";
    else if (isMinHeap(n)) cout << "Min Heap";
    else cout << "Not Heap";
}