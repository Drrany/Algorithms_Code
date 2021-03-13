#include <bits/stdc++.h>
using namespace std;
vector<int> arr, post;

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

void postTra(int i, int n) {
    if (i > n) return;
    postTra(2 * i, n);
    postTra(2 * i + 1, n);
    post.push_back(arr[i]);
}

int main() {
    int m, n;
    cin >> m >> n;
    arr.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j)
            cin >> arr[j];
        if (isMaxHeap(n)) cout << "Max Heap\n";
        else if (isMinHeap(n)) cout << "Min Heap\n";
        else cout << "Not Heap\n";
        post.clear();
        postTra(1, n);
        for (int j = 0; j < n; ++j) {
            cout << post[j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }
}