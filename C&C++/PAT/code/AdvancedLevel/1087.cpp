#include <bits/stdc++.h>

using namespace std;
int G[210][210]{};

vector<int> cur, ans;
int ansHap = 0, ansNum = 0, ansCost, avgHap;

void dfs(int u, vector<vector<int>> &pre, vector<int> &city) {
    if (u == 0) { // 到达起始点
        ansNum++;
        int curHap = 0;
        for (const auto &e:cur)
            curHap += city[e];
        if ((curHap > ansHap) || (curHap == ansHap && cur.size() < ans.size())) {
            ans.clear();
            ans.insert(ans.begin(), cur.rbegin(), cur.rend());
            ansHap = curHap;
            avgHap = ansHap / (cur.size() - 1);
        }
        return;
    }
    for (const auto &e:pre[u]) {
        cur.push_back(e);
        dfs(e, pre, city);
        cur.pop_back();
    }

}

int main() {
    int n, k, count = 0, hap, u, v, w, dst;
    unordered_map<string, int> mp1;
    unordered_map<int, string> mp2;
    string str1, str2;
    cin >> n >> k >> str1;
    mp2[count] = str1;
    mp1[str1] = count++;
    vector<int> city(n, 0);
    for (int i = 1; i < n; ++i) {
        cin >> str1 >> hap;
        mp2[count] = str1;
        mp1[str1] = count++;
        city[i] = hap;
        if (str1 == "ROM") dst = i;
    }
    for (int i = 0; i < k; ++i) {
        cin >> str1 >> str2 >> w;
        u = mp1[str1], v = mp1[str2];
        G[u][v] = G[v][u] = w;
    }
    // 找出花费最少的路
    vector<bool> visited(n, false);
    vector<vector<int>> pre(n, vector<int>());
    vector<int> dist(n, INT32_MAX);
    dist[0] = 0;
    for (int i = 0; i < n; ++i) {
        int tg = -1, minDt = INT32_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDt) {
                tg = j;
                minDt = dist[j];
            }
        }
        visited[tg] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && G[tg][j] != 0) {
                int newDt = G[tg][j] + minDt;
                if (newDt < dist[j]) {
                    dist[j] = newDt;
                    pre[j].clear();
                    pre[j].push_back(tg);
                } else if (newDt == dist[j])
                    pre[j].push_back(tg);
            }
        }
    }
    ansCost = dist[dst];
    cur.push_back(dst);
    dfs(dst, pre, city);
    cout << ansNum << " " << ansCost << " " << ansHap << " " << avgHap << "\n";
    int len = ans.size();
    for (int i = 0; i < len; ++i) {
        cout << mp2[ans[i]];
        if (i < len - 1) cout << "->";
    }
}