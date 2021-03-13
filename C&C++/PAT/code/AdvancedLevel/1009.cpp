#include <bits/stdc++.h>

using namespace std;

double coe1[1010]{};
double coe2[1010]{};
double prod[2020]{};

int main() {
    int k, ex, maxEx1 = 0, maxEx2 = 0, maxEx3 = 0;
    double co;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> ex >> co;
        coe1[ex] = co;
        maxEx1 = max(maxEx1, ex);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> ex >> co;
        coe2[ex] = co;
        maxEx2 = max(maxEx2, ex);
    }
    for (int i = 0; i <= maxEx1; ++i) {
        if (coe1[i] != 0) {
            for (int j = 0; j <= maxEx2; ++j) {
                if (coe2[j] != 0) {
                    prod[i + j] += coe1[i] * coe2[j];
                    maxEx3 = max(maxEx3, i + j);
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i <= maxEx3; ++i) {
        if (prod[i] != 0) count++;
    }
    cout << count;
    for (int i = maxEx3; i >= 0; --i) {
        if (prod[i] != 0) printf(" %d %.1f", i, prod[i]);
    }

}