#include <bits/stdc++.h>

using namespace std;

int main() {
    string num;
    cin >> num;
    if (num[0] == '-') cout << "-";
    num = num.substr(1);

    // 找到E的位置
    int i = 0, len = num.size();
    while (i < len && num[i] != 'E')
        i++;
    bool f = true;
    if (num[i + 1] == '-') f = false;
    int exp = stoi(num.substr(i + 2));
    string real = num.substr(0, i);
    // 去掉小数点
    real.erase(real.begin() + 1);
    len = real.size();

    if (f) { // 指数大于0
        int count = 0;
        while (count <= exp) {
            if (count < len)
                cout << real[count];
            else cout << '0';
            count++;
        }
        if (count < len) cout << '.' << real.substr(count);
    } else { // 指数小于0
        cout << "0.";
        int count = 1;
        while (count < exp) {
            cout << "0";
            count++;
        }
        cout << real;
    }
}