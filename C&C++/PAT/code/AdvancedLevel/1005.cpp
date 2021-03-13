#include <bits/stdc++.h>

using namespace std;

unordered_map<int, string> mp = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}
};

int main() {
    string num;
    cin >> num;
    int sum = 0;
    for (const auto &c:num) {
        sum += c - '0';
    }
    string str = to_string(sum);
    int len = str.size();
    for (int i = 0; i < len; ++i) {
        cout << mp[str[i]-'0'];
        if (i < len - 1) cout << " ";
    }

}