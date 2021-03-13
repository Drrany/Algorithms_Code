#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<int> arr(k + 1);
    vector<int> dp(k + 1, INT32_MIN / 2);  // dp[i+1]表示以arr[i]结尾(包括)的最大序列和
    vector<int> first(k + 1, 0);
    int ansLast, ans = INT32_MIN;
    bool allNeg = true;
    for (int i = 1; i <= k; ++i) {
        cin >> arr[i];
        if (arr[i] >= 0) allNeg = false;
        dp[i] = dp[i - 1] + arr[i];
        first[i] = first[i - 1];
        if (arr[i] > dp[i]) {
            dp[i] = arr[i];
            first[i] = i;
        }
        if (dp[i] > ans) {
            ans = dp[i];
            ansLast = i;
        }
    }
    if (allNeg) cout << "0 " << arr[1] << " " << arr[k];
    else cout << ans << " " << arr[first[ansLast]] << " " << arr[ansLast];
}