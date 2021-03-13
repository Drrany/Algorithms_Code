#include <bits/stdc++.h>

using namespace std;

struct money {
    int g;
    int s;
    int k;
};

money addM(money a, money b) {
    money res = {0, 0, 0};
    int carry = 0;
    carry = a.k + b.k;
    res.k = carry % 29;
    carry /= 29;

    carry += a.s + b.s;
    res.s = carry % 17;
    carry /= 17;

    carry += a.g + b.g;
    res.g = carry;

    return res;
}


int main() {
    money p, a, res;
    scanf("%d.%d.%d %d.%d.%d", &p.g, &p.s, &p.k, &a.g, &a.s, &a.k);
    res = addM(p, a);
    cout << res.g << "." << res.s << "." << res.k;
}