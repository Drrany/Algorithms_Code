// 树状数组，复习
#include <bits/stdc++.h>

using namespace std;
const int group = 317;
int mp[100010]{};
int table[group]{};


int getMedian(int n) {
    // 找第tg个元素
    int tg = ceil((double) n / 2), i = 0, count = 0;
    while (count < tg)
        count += table[i++];
    i--;
    count -= table[i];
    for (int j = i * group; j < (i + 1) * group; ++j) {
        count += mp[j];
        if (count >= tg) return j;
    }
}

int main() {
    stack<int> s;
    int n, key;
    cin >> n;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        if (str == "Pop") {
            if (s.empty()) cout << "Invalid\n";
            else {
                key = s.top();
                mp[key]--;
                table[key / group]--;
                cout << key << "\n";
                s.pop();
            }
        } else if (str == "Push") {
            cin >> key;
            mp[key]++;
            table[key / group]++;
            s.push(key);
        } else {
            if (s.empty()) cout << "Invalid\n";
            else {
                key = getMedian(s.size());
                cout << key << "\n";
            }

        }
    }
}