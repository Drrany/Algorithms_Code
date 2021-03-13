#include <bits/stdc++.h>

using namespace std;

struct node {
    int left, right;

    node(int l, int r) {
        left = l, right = r;
    }
};

int arr[100010]{};
int sum[100010]{};

int main() {
    int n, m;
    cin >> n >> m;
    // sum[i]表示arr[1..i]相加
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
    }
    vector<node> ans;
    int minLost = INT32_MAX;
    int i = 1, j = 1, rest;
    while (j <= n) {
        rest = sum[j] - sum[i - 1] - m;
        if (rest < 0) j++;
        else {
            if (rest < minLost) {
                minLost = rest;
                ans.clear();
                ans.emplace_back(i, j);
            } else if (rest == minLost)
                ans.emplace_back(i, j);
            i++;
        }
    }

    for (const auto &e:ans)
        printf("%d-%d\n", e.left, e.right);
}
