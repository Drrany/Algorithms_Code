#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, lineNum = 0;
    char c;
    cin >> n >> c;
    int k = 1;
    while ((k == 1 && n - k >= 0) || (k > 1 && n - 2 * k >= 0)) {
        if (k == 1)n -= k;
        else n -= k * 2;
        lineNum++;
        k += 2;
    }
    k -= 2;
    for (int i = 0; i < lineNum; ++i) {
        for (int j = 0; j < i; ++j)
            cout << " ";
        for (int j = i; j < k - i; ++j)
            cout << c;
        for (int j = k - i; j < k; ++j)
            cout << " ";
        cout << endl;
    }
    for (int i = lineNum - 2; i >= 0; --i) {
        for (int j = 0; j < i; ++j)
            cout << " ";
        for (int j = i; j < k - i; ++j)
            cout << c;
        for (int j = k - i; j < k; ++j)
            cout << " ";
        cout << endl;
    }
    cout << n;
}