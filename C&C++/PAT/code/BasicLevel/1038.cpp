#include <bits/stdc++.h>

using namespace std;

int main() {
    int grade[101]{};
    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int g;
        scanf("%d", &g);
        grade[g]++;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int q;
        scanf("%d", &q);
        cout << grade[q];
        if (i != k - 1)
            cout << " ";
    }
}