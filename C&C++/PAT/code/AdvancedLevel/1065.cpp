// 对于long long型，一定要用scanf输入！！！
#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    int64_t a, b, c;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        bool flag; // true表示A+B>C
        int64_t sum = a + b;
        if (a < 0 && b < 0 && sum >= 0)  // a,b都为负数
            flag = false;
        else if (a > 0 && b > 0 && sum <= 0)
            flag = true;
        else flag = (a + b) > c;
        if (flag) cout << "Case #" << i << ": true\n";
        else cout << "Case #" << i << ": false\n";
    }
}