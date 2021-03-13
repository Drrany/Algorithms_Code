#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int *arr1 = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];
    cin >> m;
    int *arr2 = new int[m];
    for (int i = 0; i < m; ++i)
        cin >> arr2[i];

    int mid = ceil((double) (m + n) / 2);

    int i = 0, j = 0;
    int ans;
    while (mid > 0) {
        if ((i < n && j < m && arr1[i] <= arr2[j]) || j >= m) {
            ans = arr1[i];
            i++;
        } else {
            ans = arr2[j];
            j++;
        }
        mid--;
    }
    cout << ans;
}