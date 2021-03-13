#include <bits/stdc++.h>
// 并查集复习
using namespace std;
vector<int> father(10010, -1);

// 加上压缩路径
int findFather(int u) {
    if (father[u] == -1) return u;
    return father[u] = findFather(father[u]);
}

int main() {
    int n, k, q, id, f1, f2, count = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k >> id;
        f1 = findFather(id);
        count = max(count, id);
        for (int j = 0; j < k - 1; ++j) {
            cin >> id;
            count = max(count, id);
            f2 = findFather(id);
            if (f1 != f2) father[f2] = f1;
        }
    }
    unordered_set<int> fa;
    for (int i = 1; i <= count; ++i)
        fa.insert(findFather(i));
    cout << fa.size() << " " << count << "\n";
    cin >> q;
    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        if (findFather(a) == findFather(b))
            cout << "Yes\n";
        else cout << "No\n";
    }
}