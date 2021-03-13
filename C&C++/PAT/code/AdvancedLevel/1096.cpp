#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ansCount = 0;
    int ansNum = 0;

    int i = 2, j = 2;
    int maxn = sqrt(n) + 1;
    while (i <= maxn) {
        int num = n;
        while (num > 0 && num % j == 0) {
            num /= j;
            j++;
        }
        if ((j - i) > ansCount) {
            ansCount = j - i;
            ansNum = i;
        }
        i++;
        j = i;
    }
    if (ansCount == 0) {
        cout << "1" << endl << n;
        return 0;
    }
    cout << ansCount << endl;
    for (int k = 0; k < ansCount; ++k) {
        cout << ansNum + k;
        if (k < ansCount - 1)
            cout << "*";
    }

}