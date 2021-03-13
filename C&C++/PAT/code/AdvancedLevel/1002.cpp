#include <bits/stdc++.h>

using namespace std;
double coe[1010]{};

int main() {
    int k, e, maxe = 0, count = 0;
    double co;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> e >> co;
        maxe = max(maxe, e);
        coe[e] += co;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> e >> co;
        maxe = max(maxe, e);
        coe[e] += co;
    }
    for (int i = maxe; i >= 0; --i) {
        if (abs(coe[i]) > 0)
            count++;
    }
    cout << count;
    for (int i = maxe; i >= 0; --i) {
        if (abs(coe[i]) > 0)
            printf(" %d %.1f", i, coe[i]);
    }

}