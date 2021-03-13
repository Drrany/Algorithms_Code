#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, id;
    cin >> n;
    string num;
    set<int> ids;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        id = 0;
        for (const auto &e:num) {
            id += e - '0';
        }
        ids.insert(id);
    }
    int len = ids.size();
    cout << len << endl;
    int t = 0;
    for (const auto &i : ids) {
        cout << i;
        t++;
        if (t < len) cout << " ";
    }


}

