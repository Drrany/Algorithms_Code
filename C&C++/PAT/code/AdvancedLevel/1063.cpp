
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, s1, s2, num;
    cin >> n;
    vector<unordered_set<int>> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        unordered_set<int> st;
        for (int j = 0; j < m; ++j) {
            cin >> num;
            if (st.find(num) == st.end())
                st.insert(num);
        }
        arr[i] = st;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> s1 >> s2;
        unordered_set<int> st1 = arr[s1];
        unordered_set<int> st2 = arr[s2];
        int nc = 0, nt;
        for (const auto &e:st1) {
            if (st2.find(e) != st2.end())
                nc++;
        }
        nt = st1.size() + st2.size() - nc;
        double ans = (double) nc / (double) nt;
        printf("%.1f%\n", ans * 100.0);
    }
}