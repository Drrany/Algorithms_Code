#include <bits/stdc++.h>

using namespace std;
int mp[129]{};

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    for (const auto &e:str2)
        mp[e]++;
    for (const auto &e:str1) {
        if (mp[e] == 0) printf("%c", e);
    }
}
