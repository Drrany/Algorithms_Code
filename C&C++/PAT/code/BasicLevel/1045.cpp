#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int *maxLeft = new int[n + 1];  // maxLeft[i]表示arr[i]左侧最大的数（不包括arr[i]）
    int *minRight = new int[n + 1]; // minRight[i]表示arr[i]右侧最小的数（不包括arr[i]）
    maxLeft[0] = 0;
    for (int i = 1; i <= n; ++i)
        maxLeft[i] = max(maxLeft[i - 1], arr[i - 1]);
    minRight[n] = (1 << 31) - 1;
    for (int i = n - 1; i >= 0; --i)
        minRight[i] = min(minRight[i + 1], arr[i]);

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int pivot = arr[i];
        if (pivot >= maxLeft[i] && pivot <= minRight[i])
            ans.push_back(pivot);
    }
    int len = ans.size();
    cout << len << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < len; ++i) {
        cout << ans[i];
        if (i < len - 1)
            cout << " ";
    }
    cout << endl;
}