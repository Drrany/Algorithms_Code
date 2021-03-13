#include <bits/stdc++.h>

using namespace std;
int table[10010]{};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        table[arr[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (table[arr[i]] == 1) {
            cout << arr[i];
            return 0;
        }
    }
    cout << "None";
}
