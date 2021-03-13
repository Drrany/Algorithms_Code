#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    int numB = 0, numS = 0;
    if (n >= 100) {
        numB = n / 100;
        n %= 100;
    }
    if (n >= 10) {
        numS = n / 10;
        n %= 10;
    }

    for (int i = 0; i < numB; ++i)
        cout << "B";
    for (int i = 0; i < numS; ++i)
        cout << "S";
    for (int i = 1; i <= n; ++i)
        cout << i;


}