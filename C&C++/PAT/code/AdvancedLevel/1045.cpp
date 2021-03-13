#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m;
    vector<int> mp(n + 1, 0);
    int fav;
    for (int i = 0; i < m; ++i) {
        cin >> fav;
        mp[fav] = i + 1;
    }
    cin >> l;
    vector<int> ori(l);
    for (int i = 0; i < l; ++i) {
        cin >> ori[i];
        ori[i] = mp[ori[i]];
    }
    // 找出单调不递减的最长子序列
    vector<int> dp(l, 1); // dp[i]表示以ori[i]结尾的不递减子序列的长度
    int ans = 1;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < i; ++j) {
            if (ori[i] >= ori[j] && ori[i] != 0 & ori[j] != 0)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}


// 最长公共子序列
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, l;  // 颜色从1~n
    cin >> n >> m;
    vector<int> fav(m);
    for (int i = 0; i < m; ++i)
        cin >> fav[i];

    cin >> l;
    vector<int> str(l);
    for (int i = 0; i < l; ++i)
        cin >> str[i];
    vector<vector<int>> dp(l + 1, vector<int>(m + 1, 0));
    // 找favStr和str的最长子序列长度
    // dp[i][j]表示str(0,i)和favStr(0,j)的最长子序列
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= m; ++j) {
            int maxNum = max(dp[i][j - 1], dp[i - 1][j]);
            if (str[i - 1] == fav[j - 1])
                dp[i][j] = maxNum + 1;
            else dp[i][j] = maxNum;
        }
    }
    cout << dp[l][m];
    return 0;
}