#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    int n1 = (len + 2) / 3 - 1;
    int n2 = len - 2 * n1;
    int i = 0, j = len - 1;
    vector<char> arr;
    while (i < n1) {
        cout << str[i++];
        for (int l = 0; l < n2 - 2; ++l)
            cout << " ";
        cout << str[j--] << "\n";
    }
    for (int l = n1; l < n1 + n2; ++l)
        cout << str[l];
}