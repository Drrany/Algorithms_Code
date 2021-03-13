#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, num;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int sum = arr[0];
    for (int i = 1; i < n; ++i)
        sum = (sum + arr[i]) / 2;
    printf("%d", sum);
}