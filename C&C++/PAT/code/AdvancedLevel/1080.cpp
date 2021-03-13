#include <bits/stdc++.h>

using namespace std;

struct info {
    int ge, gi, rank, final, id;
    vector<int> prefer;

    info(int e, int i, int k, int iid) {
        ge = e, gi = i, id = iid;
        final = ge + gi;
        prefer.resize(k);
    }
};

bool cmp(const info &a, const info &b) {
    if (a.final != b.final) return a.final > b.final;
    return a.ge > b.ge;
}

int main() {
    int n, m, k, ge, gi;
    cin >> n >> m >> k;
    vector<int> quota(m);
    vector<vector<int>> ans(m);
    vector<int> lastRank(m);
    vector<info> app;
    for (int i = 0; i < m; ++i)
        cin >> quota[i];
    for (int i = 0; i < n; ++i) {
        cin >> ge >> gi;
        app.emplace_back(ge, gi, k, i);
        for (int j = 0; j < k; ++j)
            cin >> app[i].prefer[j];
    }
    sort(app.begin(), app.end(), cmp);
    app[0].rank = 1;
    for (int i = 1; i < n; ++i) {
        if (app[i].final == app[i - 1].final && app[i].ge == app[i - 1].ge)
            app[i].rank = app[i - 1].rank;
        else app[i].rank = i + 1;
    }

    int tr;
    for (int i = 0; i < n; ++i) {
        // 遍历第i个人的选择
        vector<int> pr = app[i].prefer;
        for (int j = 0; j < k; ++j) {
            tr = pr[j];
            if (quota[tr] > 0) {
                ans[tr].push_back(app[i].id);
                quota[tr]--;
                lastRank[tr] = app[i].rank;
                break;
            } else {
                // 有排名相同且也被这个学校录取的人
                if (app[i].rank == lastRank[tr]) 
                    ans[tr].push_back(app[i].id);
            }
        }
    }

    for (auto &vi:ans) {
        int len = vi.size();
        sort(vi.begin(), vi.end());
        for (const auto &e:vi) {
            cout << e;
            if (len-- > 1) cout << " ";
        }
        cout << "\n";
    }

}










