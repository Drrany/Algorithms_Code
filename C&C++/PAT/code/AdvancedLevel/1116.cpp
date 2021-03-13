// 重做
#include <bits/stdc++.h>

using namespace std;
int mp[10000]{}; // mp[i]=j表示id为i的人排名为j

bool isPrim(int num) {
    if (num == 1) return false;
    int sq = sqrt(num);
    for (int i = 2; i <= sq; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, k, id;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> id;
        mp[id] = i;
    }
    cin >> k;
    unordered_set<int> q;
    for (int i = 0; i < k; ++i) {
        cin >> id;
        printf("%04d: ", id);
        if (mp[id] == 0) cout << "Are you kidding?\n";
        else if (q.count(id) == 0) {
            q.insert(id);
            if (mp[id] == 1) cout << "Mystery Award\n";
            else if (isPrim(mp[id])) cout << "Minion\n";
            else cout << "Chocolate\n";
        } else cout << "Checked\n";
    }
}