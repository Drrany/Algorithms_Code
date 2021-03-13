#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {

    int n;
    cin >> n;
    int ans = 0, len;
    vector<int> prime;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            prime.push_back(i);
            len = prime.size();
            if (len > 1 && prime[len - 1] - prime[len - 2] == 2)
                ans++;
        }
    }
    cout << ans;

}