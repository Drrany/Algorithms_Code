#include <bits/stdc++.h>

using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    if (sum < 0) {
        cout << "-";
        sum = -sum;
    }
    string str;
    int count = 0;
    while (sum > 0) {
        if (count % 3 == 0 && count != 0)
            str.insert(0, 1, ',');
        count++;

        char c = sum % 10 + '0';
        str.insert(0, 1, c);
        sum /= 10;
    }

    int len = str.size();
    if (len < 1)
        cout << "0";
    for (int i = 0; i < len; ++i) {
        cout << str[i];
    }
}