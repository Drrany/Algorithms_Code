#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    map<char, int> m = {{'P', 0},
                        {'A', 1},
                        {'T', 2},
                        {'e', 3},
                        {'s', 4},
                        {'t', 5}};
    char sets[] = {'P', 'A', 'T', 'e', 's', 't'};
    int times[6]{};
    int count = 0;
    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (m.find(c) != m.end()) {
            times[m[c]]++;
            count++;
        }
    }

    while (count > 0) {
        for (int i = 0; i < 6; ++i) {
            if (times[i] > 0) {
                cout << sets[i];
                times[i]--;
                count--;
            }
        }
    }

}