// 转换字符串大小写： transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
#include <bits/stdc++.h>

using namespace std;

bool isC(const char &c) {
    if ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) return true;
    return false;
}

int main() {
    string str, ans, tmp;
    int times = 0;
    getline(cin, str);
    int i = 0, j = 0, len = str.size();
    unordered_map<string, int> mp;
    while (i < len) {
        while (j < len && isC(str[j]))
            j++;
        tmp = str.substr(i, j - i);
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        mp[tmp]++;
        if (mp[tmp] > times) {
            times = mp[tmp];
            ans = tmp;
        }
        while (j < len && !isC(str[j]))
            j++;
        i = j;
    }
    cout << ans << " " << times;
}