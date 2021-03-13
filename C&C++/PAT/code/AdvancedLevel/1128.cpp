#include <bits/stdc++.h>

using namespace std;
vector<int> arr;

bool canPlace(int j) {
    for (int i = 0; i < j; ++i) {
        if (arr[i] == arr[j] || (abs(i - j) == abs(arr[i] - arr[j])))
            return false;
    }
    return true;
}


int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n;
        arr.resize(n);
        bool can = true;
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
            if (can) can = canPlace(j);
        }
        if (can) cout << "YES\n";
        else cout << "NO\n";
    }
}