// 重做
#include <bits/stdc++.h>

using namespace std;


int main() {
    string num;
    cin >> num;
    int len = num.size(), ans = 0, left, right, exp = 1;
    for (int i = len - 1; i >= 0; --i) {
        left = (i == 0) ? 0 : stoi(num.substr(0, i));
        right = (i == len - 1) ? 0 : stoi(num.substr(i + 1));
        if (num[i] == '0')
            ans += left * exp;
        else if (num[i] == '1')
            ans += left * exp + right + 1;
        else
            ans += (left + 1) * exp;
        exp *= 10;
    }
    cout << ans;
}