// 注意：十进制和其他进制的转换
#include <bits/stdc++.h>

using namespace std;

// 将radix进制的数转换成十进制
int64_t toOtherRadix(string num, int radix) {
    int64_t ans = 0, times = 1;
    reverse(num.begin(), num.end());
    for (const auto &c:num) {
        if (c >= '0' && c <= '9')
            ans += (c - '0') * times;
        else ans += (c - 'a' + 10) * times;
        times *= radix;
    }
    return ans;
}


int main() {
    string n1, n2;
    int tag, radix;
    int64_t num1, num2;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 1) swap(n1, n2);

    // 判断n1最低是几进制
    int64_t lowR = 1;
    char tmpMax = '0';
    for (const auto &c:n1) {
        tmpMax = max(tmpMax, c);
    }
    if (tmpMax >= '0' && tmpMax <= '9') lowR = tmpMax - '0' + 1;
    else lowR = tmpMax - 'a' + 11;

    num2 = toOtherRadix(n2, radix);
    int64_t highR = max(lowR, num2), midR;
    while (lowR <= highR) {
        midR = (lowR + highR) / 2;
        num1 = toOtherRadix(n1, midR);
        if (num1 == num2) {
            cout << midR;
            return 0;
        } else if (num1 > num2 || num1 < 0)
            highR = midR - 1;
        else lowR = midR + 1;
    }
    cout << "Impossible";
}