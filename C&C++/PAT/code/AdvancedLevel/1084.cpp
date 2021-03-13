#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    unordered_set<char> good, worn;
    for (const auto &c:str2)
        good.insert(c);
    for (const auto &c:str1) {
        if ((good.find(c) == good.end()) && (worn.find(c) == worn.end())) {
            worn.insert(c);
            cout << c;
        }
    }
}