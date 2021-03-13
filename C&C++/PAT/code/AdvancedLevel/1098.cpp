#include <bits/stdc++.h>
using namespace std;
vector<int> ori, res, ans;

bool isInsert(int n) {
    vector<int> arr(ori);
    for (int i = 2; i <= n; ++i) {
        sort(arr.begin() + 1, arr.begin() + i + 1);
        if (arr == res) {
            sort(arr.begin() + 1, arr.begin() + i + 2);
            ans = arr;
            return true;
        }
    }
    return false;
}

void adjust(int root, int n) {
    int left = -1, right = -1;
    if (root * 2 <= n) left = ori[root * 2];
    if (root * 2 + 1 <= n) right = ori[root * 2 + 1];
    if (left == -1) return;
    int tg = root * 2;
    if (right > left) tg++;
    if (ori[tg] > ori[root]) {
        swap(ori[root], ori[tg]);
        adjust(tg, n);
    }
}


void heapSort(int n) {
    bool flag = false;
    // 自下向上调整，从最后一个有孩子的结点到根节点
    for (int i = n / 2; i >= 1; --i)
        adjust(i, n);
    // 每次取根节点将其放在最后
    for (int i = 1; i <= n; ++i) {
        swap(ori[1], ori[n - i + 1]);
        // 自上向下调整
        adjust(1, n - i);
        if (flag) return;
        if (ori == res) flag = true;
    }
}

int main() {
    int n;
    cin >> n;
    ori.resize(n + 1);
    res.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> ori[i];
    for (int i = 1; i <= n; ++i)
        cin >> res[i];
    if (isInsert(n)) {
        cout << "Insertion Sort\n";
        for (int i = 1; i <= n; ++i) {
            cout << ans[i];
            if (i < n) cout << " ";
        }
    } else {
        cout << "Heap Sort\n";
        heapSort(n);
        for (int i = 1; i <= n; ++i) {
            cout << ori[i];
            if (i < n) cout << " ";
        }
    }
}