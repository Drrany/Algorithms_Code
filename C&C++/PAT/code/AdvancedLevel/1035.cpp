#include <bits/stdc++.h>

using namespace std;

struct info {
    string name, password;

    info(string n, string p) {
        name = n, password = p;
    }
};

int main() {
    int n;
    cin >> n;
    string name, pwd;
    vector<info> ans;
    for (int i = 0; i < n; ++i) {
        cin >> name >> pwd;
        string str;
        for (const auto &c:pwd) {
            if (c == '1') str += '@';
            else if (c == '0') str += '%';
            else if (c == 'l') str += 'L';
            else if (c == 'O') str += 'o';
            else str += c;
        }
        if (str != pwd)
            ans.emplace_back(name, str);
    }
    int len = ans.size();
    if (len == 0) {
        if (n == 1)
            cout << "There is " << n << " account and no account is modified";
        else cout << "There are " << n << " accounts and no account is modified";
    } else {
        cout << len << "\n";
        for (const auto &e:ans)
            cout << e.name << " " << e.password << "\n";
    }


}