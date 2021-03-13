#include <bits/stdc++.h>

using namespace std;

int main() {
    string num;
    vector<string> ans;
    map<int, string> mp = {
            {1, "yi"},
            {2, "er"},
            {3, "san"},
            {4, "si"},
            {5, "wu"},
            {6, "liu"},
            {7, "qi"},
            {8, "ba"},
            {9, "jiu"}
    };
    map<int, string> mp2 = {
            {2, "Shi"},
            {3, "Bai"},
            {4, "Qian"}
    };
    cin >> num;
    int tmp = stoi(num);
    if (tmp == 0) {
        cout << "ling";
        return 0;
    }
    if (num[0] == '-') {
        cout << "Fu ";
        num = num.substr(1);
    }
    int len = num.size();
    int i = 0;
    int lowBit = min(4, len);
    int midBit = min(4, len - 4);
    int highBit = max(0, len - 8);
    if (highBit > 0) {
        tmp = num[i++] - '0';
        ans.push_back(mp[tmp]);
        ans.emplace_back("Yi");
        len--;
    }
    // 输出万位
    if (midBit > 0) {
        string mid = num.substr(i, midBit);
        if (stoi(mid) != 0) {
            for (int j = 0; j < midBit; ++j) {
                tmp = mid[j] - '0';
                if (tmp == 0) {
                    if ((j < midBit - 1) && mid[j + 1] != '0')
                        ans.emplace_back("ling");
                } else {
                    ans.push_back(mp[tmp]);
                    if (midBit - j != 1)
                        ans.push_back(mp2[midBit - j]);
                }
            }
            ans.emplace_back("Wan");
        }
        i += midBit;
    }
    // 输出低4位
    if (lowBit > 0) {
        string low = num.substr(i);
        if (stoi(low) != 0) {
            for (int j = 0; j < lowBit; ++j) {
                tmp = low[j] - '0';
                if (tmp == 0) {
                    if ((j < lowBit - 1) && low[j + 1] != '0')
                        ans.emplace_back("ling");
                } else {
                    ans.push_back(mp[tmp]);
                    if (lowBit - j != 1)
                        ans.push_back(mp2[lowBit - j]);
                }
            }
        }
    }
    int si = ans.size();
    for (int j = 0; j < si; ++j) {
        cout << ans[j];
        if (j < si - 1) cout << " ";
    }
}










