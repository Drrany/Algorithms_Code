// 0和1不是质数，2是最小的质数，所以0、1要特判
// 使用cout在数字前补足k个0：cout << setw(k) << setfill('0') << num;


#include <bits/stdc++.h>

using namespace std;

bool isPrim(int num) {
    if (num == 0 || num == 1) return false;
    int sq = sqrt(num);
    for (int i = 2; i <= sq; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int l, k;
    cin >> l >> k;
    cin.ignore();
    string num;
    getline(cin, num);

    int tmpNum;
    for (int i = 0; i <= l - k; ++i) {
        tmpNum = stoi(num.substr(i, k));
        if (isPrim(tmpNum)) {
            cout << setw(k) << setfill('0') << tmpNum;
            return 0;
        }
    }
    cout << "404";
}