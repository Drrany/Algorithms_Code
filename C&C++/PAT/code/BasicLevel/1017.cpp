#include <bits/stdc++.h>

using namespace std;

struct bigNum {
    int b[1001]{};
    int len;

    bigNum() {
        fill(b, b + 1001, 0);
        len = 0;
    }
};

void toArray(string str, bigNum &num) {
    int len = str.length();
    for (int i = 0; i < len; ++i)
        num.b[i] = str[len - i - 1] - '0';
    num.len = len;
}

void bigDivide(bigNum num, int divider, bigNum &quotient, int &remainder) {
    int *b = num.b;
    for (int i = num.len - 1; i >= 0; i--) {
        int unit = remainder * 10 + b[i];
        if (unit < divider) {
            quotient.b[(quotient.len)++] = 0;
            remainder = unit;
        } else {
            quotient.b[(quotient.len)++] = unit / divider;
            remainder = unit % divider;
        }
    }
    // 删除商多余前缀0
    int pre = 0;
    while (quotient.len > 1 && quotient.b[pre] == 0) {
        quotient.len--;
        pre++;
    }
    for (int i = 0; i < quotient.len; ++i)
        quotient.b[i] = quotient.b[i + pre];
}

int main() {
    string tmp;
    int divider, remainder = 0;
    cin >> tmp >> divider;
    bigNum num, quotient;
    toArray(tmp, num);
    bigDivide(num, divider, quotient, remainder);

    for (int i = 0; i < quotient.len; ++i)
        cout << quotient.b[i];
    cout << " " << remainder;
}