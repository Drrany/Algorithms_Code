#include <bits/stdc++.h>

using namespace std;
const int maxn = 130;
int mp[maxn]{};

int main() {
    string str, ori;
    cin >> str >> ori;
    int rest = 0, lack = 0;
    for (const auto &c:str)
        mp[c]++;
    for (const auto &c:ori) {
        mp[c]--;
        if (mp[c] < 0) lack++;
    }
    if (lack > 0) cout << "No " << lack;
    else {
        for (int i = 0; i < maxn; ++i)
            rest += mp[i];
        cout << "Yes " << rest;
    }
}