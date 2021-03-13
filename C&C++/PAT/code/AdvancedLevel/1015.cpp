#include <bits/stdc++.h>

using namespace std;

int convert(int num, int radix) {
    string rev;
    while (num != 0) {
        rev += (char) (num % radix + '0');
        num /= radix;
    }
    int res = 0;
    for (const auto &c:rev) {
        res *= radix;
        res += c - '0';
    }
    return res;
}

bool isPrim(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int num, radix;
    while (true) {
        cin >> num;
        if (num >= 0) {
            cin >> radix;
            // 将num转换为radix进制，并翻转，再转换成十进制
            int rev = convert(num, radix);
            if (isPrim(rev)&&isPrim(num))
                cout << "Yes\n";
            else cout << "No\n";
        } else break;
    }
}