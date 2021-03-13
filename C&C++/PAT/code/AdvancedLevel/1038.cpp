// 重做
#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b < b + a;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);
    string ans;
    for (const auto &str:arr)
        ans += str;
    // 去掉ans的前导零
    int i = 0, len = ans.size();
    while (i < len && ans[i] == '0') i++;
    if (i == len) cout << "0";
    else cout << ans.substr(i);
}
