#include <bits/stdc++.h>
// 重做
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> st(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> st[i];

    // 假设i和j是狼人
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vector<int> flag(n + 1, 1);
            flag[i] = flag[j] = -1; // i和j是狼人
            vector<int> liar;
            for (int k = 1; k <= n; ++k) {
                int tg = abs(st[k]);
                if (st[k] * flag[tg] < 0) // k说的话与事实不符
                    liar.push_back(k);
            }
            if ((liar.size() == 2) && ((flag[liar[0]] + flag[liar[1]]) == 0)) { // 如果恰有两人说谎且i和j中恰有一人说谎
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";

}