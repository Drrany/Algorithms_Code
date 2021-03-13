// 二次探测法：pos=(key+d)%len (d=0, 1^2, -1^2, 2^2, -2^2,……, q^2, -q^2, q <= len/2)
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}


bool insertNum(vector<int> &mp, int num, int len, int &pos) {
    for (int i = 0; i <= len / 2; ++i) {
        pos = (num + (i * i)) % len;
        if (mp[pos] == -1) {
            mp[pos] = num;
            return true;
        }
    }
    return false;
}

int main() {
    int len, n, num, pos;
    bool flag;
    cin >> len >> n;
    while (!isPrime(len)) len++;
    vector<int> mp(len, -1);
    for (int i = 0; i < n; ++i) {
        cin >> num;
        flag = insertNum(mp, num, len, pos);
        if (flag) cout << pos;
        else cout << "-";
        if (i < n - 1) cout << " ";
    }
}