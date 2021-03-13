#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 100010;
int arr[MAXSIZE];
int n, p;

int maxLen(int i) {
    long long num = arr[i] * p;
    if (arr[n - 1] <= num) return n;
    int l = i + 1, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] <= num)
            l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int j = maxLen(i);
        ans = max(ans, j - i);
    }
    cout << ans;
}

// 双指针

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    int ans = 0;
    int64_t pro;
    for (int i = 0; i < n; ++i) {
        for (int j = i + ans; j < n; ++j) {
            pro = v[i] * p;
            if (v[j] <= pro)
                ans = max(ans, j - i + 1);
            else break;
        }
    }
    cout << ans;

}