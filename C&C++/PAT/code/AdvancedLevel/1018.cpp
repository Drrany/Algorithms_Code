#include <bits/stdc++.h>

using namespace std;
int G[510][510]{};

vector<int> cur, ans, bikes;
int cm, sp, ansRest = 0, ansNeed = INT32_MAX;

void dfs(const vector<vector<int>> &pre, int n, int u) {
    if (u == 0) {
        // 计算需要携带的自行车数目
        int rest = 0, need = 0;
        for (int i = cur.size() - 2; i >= 0; --i) {
            int loc = cur[i];
            if (bikes[loc] < 0) { // 若不够perfect
                if (rest + bikes[loc] >= 0)
                    rest += bikes[loc];
                else {
                    bikes[loc] += rest;
                    rest = 0;
                    need += -bikes[loc];
                }
            } else
                rest += bikes[loc];
        }
        if (need < ansNeed) {
            ansNeed = need;
            ansRest = rest;
            ans = cur;
        } else if (need == ansNeed && rest < ansRest) {
            ansRest = rest;
            ans = cur;
        }
        return;
    }
    vector<int> next = pre[u];
    for (int i = 0; i < next.size(); ++i) {
        cur.push_back(next[i]);
        dfs(pre, n, next[i]);
        cur.pop_back();
    }
}


int main() {
    int n, m, u, v, w;
    cin >> cm >> n >> sp >> m;
    cm /= 2;
    bikes.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> bikes[i];
        bikes[i] -= cm;
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    // 找出所有最短路径
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INT32_MAX);
    vector<vector<int>> pre(n + 1, vector<int>());
    dist[0] = 0;
    for (int i = 0; i <= n; ++i) {
        int tg = -1, minDt = INT32_MAX;
        for (int j = 0; j <= n; ++j) {
            if (!visited[j] && dist[j] < minDt) {
                minDt = dist[j];
                tg = j;
            }
        }
        visited[tg] = true;
        for (int j = 0; j <= n; ++j) {
            if (!visited[j] && G[j][tg] > 0) {
                if (dist[tg] + G[j][tg] < dist[j]) {
                    dist[j] = dist[tg] + G[j][tg];
                    pre[j].clear();
                    pre[j].push_back(tg);
                } else if (dist[tg] + G[j][tg] == dist[j])
                    pre[j].push_back(tg);
            }
        }
    }

    // 得到所有最短路径
    cur.push_back(sp);
    dfs(pre, n, sp);
    cout << ansNeed << " 0";
    for (int i = ans.size() - 2; i >= 0; --i)
        cout << "->" << ans[i];
    cout << " " << ansRest;
}
