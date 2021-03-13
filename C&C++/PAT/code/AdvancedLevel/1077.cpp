#include <bits/stdc++.h>

using namespace std;

string getSame(const string &str1, const string &str2) {
    int i = str1.size() - 1, j = str2.size() - 1;
    string ans;
    while (i >= 0 && j >= 0) {
        if (str1[i] == str2[j]) {
            ans += str1[i];
            i--, j--;
        } else break;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string ans, str;
    getline(cin, ans);
    for (int i = 1; i < n; ++i) {
        getline(cin, str);
        ans = getSame(ans, str);
    }
    if (ans.empty()) cout << "nai";
    else cout << ans;
}










