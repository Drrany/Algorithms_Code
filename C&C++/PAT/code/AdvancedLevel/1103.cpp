#include <bits/stdc++.h>

using namespace std;
vector<int> ans, cur;
int ansTotal, curTotal;
int n, ansLen, powSize;

void dfs(int num, int fac, int curLen) {
    if (curLen == ansLen) {
        if (num == 0) {
            if (ans.empty())
                ans = cur;
            else {
                ansTotal = 0, curTotal = 0;
                for (int i = 0; i < ansLen; ++i) {
                    ansTotal += ans[i];
                    curTotal += cur[i];
                }
                if (curTotal > ansTotal) ans = cur;
                else if (curTotal == ansTotal) {
                    for (int i = 0; i < ansLen; ++i) {
                        if (cur[i] > ans[i]) {
                            ans = cur;
                            break;
                        } else if (cur[i] < ans[i]) break;
                    }
                }
            }
        }
        return;
    }
    for (int i = fac; i >= 1; --i) {
        int d = pow(i, powSize);
        if (d > num) continue;
        cur.push_back(i);
        dfs(num - d, i, curLen + 1);
        cur.pop_back();
    }
}


int main() {
    cin >> n >> ansLen >> powSize;
    int maxn;
    for (int i = 1; i < n; ++i) {
        if (pow(i, powSize) > n) {
            maxn = i;
            break;
        }
    }
    dfs(n, maxn, 0);
    if (ans.empty()) cout << "Impossible";
    else {
        cout << n << " = ";
        for (int i = 0; i < ansLen; ++i) {
            cout << ans[i] << "^" << powSize;
            if (i < ansLen - 1) cout << " + ";
        }
    }
}