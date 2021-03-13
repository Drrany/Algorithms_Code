#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c, k;
    cin >> n;
    string num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        c = stoi(num);
        k = num.size() / 2;
        a = stoi(num.substr(0, k));
        b = stoi(num.substr(k));
        if (a == 0 || b == 0) cout << "No\n";
        else if (c % (a * b) == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}