#include <bits/stdc++.h>
using namespace std;
const int maxn = 100011;

vector<unordered_set<int>> mp(maxn, unordered_set<int>());

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num > 0)
            mp[num % maxn].insert(num);
    }
    for (int i = 1; i < maxn; ++i) {
        if (mp[i].count(i) == 0) {
            cout << i;
            return 0;
        }
    }
}