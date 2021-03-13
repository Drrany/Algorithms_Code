// 如何得到最小公倍数：(a*b)/(a和b的最大公约数)
// 如何得到最大公约数：见下
// 0需要特判
#include <bits/stdc++.h>

using namespace std;

struct Format {
    int64_t up, down;
};
int integer = 0;

int64_t getGCD(int64_t a, int64_t b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int64_t getLcm(int64_t a, int64_t b) {
    int64_t gcd = (a > b) ? getGCD(a, b) : getGCD(b, a);
    return (a / gcd) * b;
}

void addTwo(Format &a, Format b) {
    // 找出a和b分母的最小公倍数
    int64_t lcm = getLcm(a.down, b.down);
    int64_t t1 = lcm / a.down, t2 = lcm / b.down;
    a.down = b.down = lcm;
    a.up *= t1, b.up *= t2;
    a.up += b.up;
    // 得到整数部分
    while (a.up >= a.down) {
        integer++;
        a.up -= a.down;
    }
    while (abs(a.up) >= a.down) {
        integer--;
        a.up += a.down;
    }
    // 找出a分子分母的最大公倍数
    int64_t gcd = (abs(a.up) > a.down) ? getGCD(abs(a.up), a.down) : getGCD(a.down, abs(a.up));
    a.up /= gcd, a.down /= gcd;
}

int main() {
    int n;
    cin >> n;
    Format ans = {0, 1};
    Format tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        addTwo(ans, tmp);
    }
    if (integer != 0) cout << integer;
    if (integer != 0 && ans.up != 0) cout << " ";
    if (ans.up != 0) cout << ans.up << "/" << ans.down;
    if (integer == 0 && ans.up == 0) cout << "0";
}