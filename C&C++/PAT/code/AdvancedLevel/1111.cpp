#include <bits/stdc++.h>
using namespace std;
int Glen[510][510]{};
int Gtime[510][510]{};
int src, dst, ansTime, ansLen;
vector<int> timePath, lenPath, curPath;

void getShortest(int n) {
    vector<int> dist(n, INT32_MAX);
    vector<int> times(n, INT32_MAX);
    vector<int> visited(n, false);
    vector<int> pre(n);
    dist[src] = 0, times[src] = 0;
    for (int i = 0; i < n; ++i) {
        int tg = -1, minDt = INT32_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDt) {
                minDt = dist[j];
                tg = j;
            }
        }
        visited[tg] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && Glen[tg][j] != 0) {
                int newLen = dist[tg] + Glen[tg][j];
                int newTime = times[tg] + Gtime[tg][j];
                if ((newLen < dist[j]) || (newLen == dist[j] && newTime < times[j])) {
                    dist[j] = newLen;
                    pre[j] = tg;
                    times[j] = newTime;
                }
            }
        }
    }
    ansLen = dist[dst];
    int p = dst;
    while (p != src) {
        lenPath.insert(lenPath.begin(), p);
        p = pre[p];
    }
}

void dfs(const vector<vector<int>> &pre, int u) {
    if (u == src) {
        if ((timePath.empty()) || (timePath.size() > curPath.size())) {
            timePath.clear();
            timePath.insert(timePath.begin(), curPath.rbegin(), curPath.rend());
        }
        return;
    }
    curPath.push_back(u);
    vector<int> next = pre[u];
    for (const auto &e:next)
        dfs(pre, e);
    curPath.pop_back();
}

void getFastest(int n) {
    vector<int> dist(n, INT32_MAX);
    vector<int> visited(n, false);
    vector<vector<int>> pre(n, vector<int>());
    dist[src] = 0;
    for (int i = 0; i < n; ++i) {
        int tg = -1, minDt = INT32_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDt) {
                minDt = dist[j];
                tg = j;
            }
        }
        visited[tg] = true;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && Gtime[tg][j] != 0) {
                int newTime = dist[tg] + Gtime[tg][j];
                if (newTime < dist[j]) {
                    dist[j] = newTime;
                    pre[j].clear();
                    pre[j].push_back(tg);
                } else if (newTime == dist[j])
                    pre[j].push_back(tg);
            }
        }
    }
    ansTime = dist[dst];
    // 遍历所有路径
    dfs(pre, dst);
}

int main() {
    int n, m, u, v, len, time, one;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> one >> len >> time;
        Glen[u][v] = len;
        Gtime[u][v] = time;
        if (one == 0) {
            Glen[v][u] = len;
            Gtime[v][u] = time;
        }
    }
    cin >> src >> dst;
    getShortest(n);
    getFastest(n);
    if (lenPath == timePath) {
        cout << "Distance = " << ansLen << "; " << "Time = " << ansTime << ": " << src;
        for (const auto &e:timePath)
            cout << " -> " << e;
    } else {
        cout << "Distance = " << ansLen << ": " << src;
        for (const auto &e:lenPath)
            cout << " -> " << e;
        cout << "\nTime = " << ansTime << ": " << src;
        for (const auto &e:timePath)
            cout << " -> " << e;
    }

}