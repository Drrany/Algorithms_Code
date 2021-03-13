#include <bits/stdc++.h>

using namespace std;

int main() {
    string ori, res;
    cin >> ori;
    char tb1[10]{}, tb2[10]{};
    int carry = 0, len = ori.size();
    for (int i = len - 1; i >= 0; --i) {
        tb1[ori[i] - '0']++;
        int sum = (ori[i] - '0') * 2 + carry;
        carry = sum / 10;
        res += (char) (sum % 10 + '0');
        tb2[sum % 10]++;
    }
    if (carry > 0) {
        res += '1';
        tb2[1]++;
    }
    bool flag = true;
    for (int i = 0; i < 10; ++i) {
        if (tb1[i] != tb2[i]) {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Yes\n";
    else cout << "No\n";
    reverse(res.begin(), res.end());
    cout << res;
}