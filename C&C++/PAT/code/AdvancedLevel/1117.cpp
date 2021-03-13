#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), ::greater<>());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int e = min(i + 1, arr[i] - 1);
        ans = max(ans, e);
    }
    cout << ans;
}