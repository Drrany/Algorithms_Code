// 重做
// 如果是找序列，则原序列的顺序没有那么重要
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + ans; j < n; ++j) {
            if (p >= ((double) arr[j] / (double) arr[i]))
                ans = max(ans, j - i + 1);
            else break;
        }
    }
    cout << ans;
}