#include <bits/stdc++.h>

using namespace std;
int G[1020][1020]{}; // n+1~n+m为gas station

int totalRes = 0;         // 和居民区的距离总和
int resN;
int serverDis;            // 服务范围
int ans = -1, mini = 0;

void calculate(int u, int n) {
    vector<int> dist(n + 1, INT32_MAX);
    vector<bool> visited(n + 1, false);
    dist[u] = 0;
    for (int i = 0; i < n; ++i) {
        int tg = -1, minDt = INT32_MAX;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && dist[j] < minDt) {
                minDt = dist[j];
                tg = j;
            }
        }
        if (tg == -1) { // 若无法到达，判断是否所有居民地区都到达了
            for (int j = 1; j <= resN; ++j) {
                if (!visited[j]) return;
            }
            break;
        }
        // 若到居民区的距离大于服务范围
        if (tg <= resN && minDt > serverDis) return;
        visited[tg] = true;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && G[j][tg] != 0)
                dist[j] = min(dist[j], minDt + G[j][tg]);
        }

    }
    int curRes = 0, curMini = INT32_MAX;
    for (int i = 1; i <= resN; ++i) {
        curRes += dist[i];
        curMini = min(curMini, dist[i]);
    }
    if ((curMini > mini) || (curMini == mini && curRes < totalRes)) { // 新的最优解
        ans = u;
        mini = curMini;
        totalRes = curRes;
    }
}

int main() {
    int m, k, u, v, d;
    cin >> resN >> m >> k >> serverDis;
    string a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b >> d;
        if (a[0] == 'G') u = stoi(a.substr(1)) + resN;
        else u = stoi(a);
        if (b[0] == 'G') v = stoi(b.substr(1)) + resN;
        else v = stoi(b);
        G[u][v] = G[v][u] = d;
    }
    // 遍历每个可选加油站位置
    for (int i = resN + 1; i <= resN + m; ++i)
        calculate(i, resN + m);
    if (ans == -1) cout << "No Solution";
    else {
        cout << 'G' << ans - resN << "\n";
        double avg = (double) totalRes / (double) resN;
        avg = round(avg * 10) / 10.0;
        printf("%.1f %.1f", (double) mini, avg);
    }
}