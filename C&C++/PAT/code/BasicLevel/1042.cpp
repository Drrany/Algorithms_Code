#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int times[26]{};

    int maxTimes = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';
            if (str[i] >= 'a' && str[i] <= 'z') {
                times[str[i] - 'a']++;
                maxTimes = max(maxTimes, times[str[i] - 'a']);
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (times[i] == maxTimes) {
            cout << (char) (i + 'a') << " " << maxTimes;
            break;
        }
    }


}