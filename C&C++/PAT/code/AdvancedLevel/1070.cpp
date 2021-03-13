// 有一个测试点错误，将所有值设置为double后通过
#include <bits/stdc++.h>

using namespace std;

struct cake {
    double amount;
    double price;
    double per;

    cake(double m, double p) {
        amount = m, price = p;
        per = p / m;
    }
};

bool cmp(const cake &a, const cake &b) {
    return a.per > b.per;
}

int main() {
    int n;
    double d;
    cin >> n >> d;
    vector<cake> arr;
    vector<double> amount(n);
    vector<double> price(n);
    for (int i = 0; i < n; ++i)
        cin >> amount[i];
    for (int i = 0; i < n; ++i)
        cin >> price[i];
    for (int i = 0; i < n; ++i)
        arr.emplace_back(amount[i], price[i]);
    sort(arr.begin(), arr.end(), cmp);
    double ans = 0.0;
    int i = 0;
    while (d > 0 && i < n) {
        if (d >= arr[i].amount) {
            ans += arr[i].price;
            d -= arr[i].amount;
        } else {
            ans += d * arr[i].per;
            d = 0;
        }
        i++;
    }
    printf("%.2f", ans);
}

