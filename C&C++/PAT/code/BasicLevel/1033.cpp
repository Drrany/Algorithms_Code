#include <bits/stdc++.h>

using namespace std;

int main() {
    string tmp, str;
    cin >> tmp >> str;
    bool wrong[128]{};
    for (int i = 0; i < tmp.size(); ++i) {
        if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            wrong[tmp[i] + 'a' - 'A'] = true;
        wrong[tmp[i]] = true;
    }
    bool canCaps = !wrong['+'];
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            if (canCaps && !wrong[str[i]])
                cout << str[i];
        } else if (!wrong[str[i]])
            cout << str[i];
    }
    cout << endl;
}