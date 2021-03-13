// 浮点数相加有误差，转换为整型再相加
#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    double num;
    int64_t ans = 0;
    cin >> n;
    int r = n;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        ans += (int64_t) ((1000 * num) * i * r);
        r--;
    }
    printf("%.2f", ans / 1000.0);

}
