#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, tmp, cur = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp > cur)
            ans += (tmp - cur) * 6;
        else ans += (cur - tmp) * 4;
        ans += 5;
        cur = tmp;
    }
    cout << ans;
}