#include <bits/stdc++.h>

using namespace std;

string to13(int num) {
    string res;
    while (num != 0) {
        int md = num % 13;
        if (md >= 0 && md <= 9)
            res.insert(0, 1, (char) (md + '0'));
        else res.insert(0, 1, (char) (md - 10 + 'A'));
        num /= 13;
    }
    return res.empty() ? "0" : res;
}

int main() {
    string ans = "#";
    int num;
    for (int i = 0; i < 3; ++i) {
        cin >> num;
        string res = to13(num);
        if (res.size() < 2)
            ans += "0" + res;
        else ans += res;
    }
    cout << ans;
}