#include <bits/stdc++.h>

using namespace std;

// 一组数字分成两个集合，两个集合的个数差最小，和差最大
int main() {
    int n, sum = 0, sum1 = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n / 2; ++i)
        sum1 += arr[i];
    if (n % 2 == 0)
        cout << "0 " << abs(sum - 2 * sum1);
    else cout << "1 " << abs(sum - 2 * sum1);
}