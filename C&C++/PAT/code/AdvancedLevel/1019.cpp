#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    if (n == 0) {
        cout << "Yes\n0";
        return 0;
    }
    vector<int> num;
    while (n != 0) {
        num.push_back(n % b);
        n /= b;
    }
    int len = num.size();
    int i = 0, j = len - 1;
    bool flag = true;
    while (i != j) {
        if (num[i] != num[j]) {
            flag = false;
            break;
        } else
            i++, j--;
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";

    for (int k = len - 1; k >= 0; --k) {
        cout << num[k];
        if (k > 0) cout << " ";
    }
}