#include <bits/stdc++.h>

using namespace std;

void construct(string &cur) {
    int len = cur.size();
    string next;
    int i = 0, j = 0;
    while (i < len) {
        while (j < len && cur[i] == cur[j])
            j++;
        next += cur[i] + to_string(j - i);
        i = j;
    }
    cur = next;
}

int main() {
    int d, n;
    cin >> d >> n;
    string ans = to_string(d);
    for (int i = 1; i < n; ++i)
        construct(ans);
    cout << ans;
}