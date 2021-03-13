#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000007;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    int ans = 0;
    // leftP[i]表示第i个字符左侧P的数量
    // rightT[i]表示第i个字符右侧T的数量
    vector<int> leftP(len, 0);
    vector<int> rightT(len, 0);
    for (int i = 1; i < len; ++i) {
        if (str[i - 1] == 'P') leftP[i] = leftP[i - 1] + 1;
        else leftP[i] = leftP[i - 1];
    }
    for (int i = len - 2; i >= 0; i--) {
        if (str[i + 1] == 'T') rightT[i] = rightT[i + 1] + 1;
        else rightT[i] = rightT[i + 1];
    }
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'A')
            ans = (leftP[i] * rightT[i] + ans) % maxn;
    }
    cout << ans;

}