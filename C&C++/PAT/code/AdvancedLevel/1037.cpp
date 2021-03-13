#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {

    int nc, np;
    cin >> nc;
    vector<int> coupons(nc);
    for (int i = 0; i < nc; ++i)
        cin >> coupons[i];
    cin >> np;
    vector<int> products(np);
    for (int i = 0; i < np; ++i)
        cin >> products[i];
    sort(coupons.begin(), coupons.end(), cmp);
    sort(products.begin(), products.end(), cmp);
    int ans = 0, cb = 0, pb = 0, ce = nc - 1, pe = np - 1;
    // 处理都为正数和都为负数的部分
    while (cb < nc && pb < np && coupons[cb] > 0 && products[pb] > 0)
        ans += coupons[cb++] * products[pb++];
    while (ce >= 0 && pe >= 0 && coupons[ce] < 0 && products[pe] < 0)
        ans += coupons[ce--] * products[pe--];
    cout << ans;


}
