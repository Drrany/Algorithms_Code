#include <bits/stdc++.h>

using namespace std;


int main() {
    int arr[10]{};
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        int j = str[i] - '0';
        arr[j]++;
    }
    for (int i = 0; i < 10; ++i) {
        if (arr[i] != 0)
            cout << i << ":" << arr[i] << endl;
    }
}