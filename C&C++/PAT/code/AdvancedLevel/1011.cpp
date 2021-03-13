#include <bits/stdc++.h>

using namespace std;

char m[3] = {'W', 'T', 'L'};

int main() {
    double p[3][3];
    double profit = 1.0;
    for (int i = 0; i < 3; ++i) {
        int index = 0;
        for (int j = 0; j < 3; ++j) {
            cin >> p[i][j];
            if (p[i][j] >= p[i][index])
                index = j;
        }
        cout << m[index] << " ";
        profit *= p[i][index];
    }
    profit = (profit * 0.65 - 1) * 2.0;
    printf("%.2f", profit);

}