// 重做 用队列
#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, k, num;
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        stack<int> s;
        queue<int> q;
        for (int j = 0; j < n; ++j) {
            cin >> num;
            q.push(num);
        }
        for (int j = 1; j <= n; ++j) {
            s.push(j);
            if (s.size() > m)
                break;
            while (!s.empty() && s.top() == q.front()) {
                s.pop();
                q.pop();
            }
        }
        if (s.empty())
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}