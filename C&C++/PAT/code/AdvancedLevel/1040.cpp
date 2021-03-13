#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int len = str.size();
    // dp[i][j]表示str(i,j)是否是回文串
    vector<vector<bool>> dp(len + 1, vector<bool>(len + 1, false));
    for (int i = 0; i < len; ++i)
        dp[i][i] = true;
    int maxLen = 1;
    for (int gap = 1; gap < len; ++gap) {
        for (int i = 0; i < len - gap; ++i) {
            int j = i + gap;
            if (gap == 1) {
                if (str[i] == str[j])
                    dp[i][j] = true;
            } else if (dp[i + 1][j - 1] && str[i] == str[j])
                dp[i][j] = true;
            if (dp[i][j])
                maxLen = max(maxLen, j - i + 1);
        }
    }
    cout << maxLen;
}

