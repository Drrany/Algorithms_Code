// 要注意答案是否要固定几位输出！！！！！

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v;
    int line;

    Edge(int iu, int iv, int il) {
        u = iu, v = iv, line = il;
    }
};

vector<vector<Edge>> G(10000);
vector<bool> visited;
vector<Edge> ans, path;
int minTrans, curTrans, minStop, curStop;
int st, dt;

void dfs(int u) {
    if (u == dt) {
        if (curStop <= minStop) {
            // 计算转站次数
            curTrans = 0;
            vector<Edge> tmp;
            tmp.emplace_back(path[0].u, path[0].v, path[0].line);
            for (int i = 1; i < path.size(); ++i) {
                if (path[i].line != path[i - 1].line) {
                    tmp.emplace_back(path[i].u, path[i].v, path[i].line);
                    curTrans++;
                } else tmp[curTrans].v = path[i].v;
            }
            if (curStop < minStop || (curStop == minStop && curTrans < minTrans)) {
                minStop = curStop;
                minTrans = curTrans;
                ans = tmp;
            }
        }
    } else {
        vector<Edge> next = G[u];
        for (const auto &e:next) {
            if (!visited[e.v]) {
                curStop++;
                path.push_back(e);
                visited[e.v] = true;
                dfs(e.v);
                visited[e.v] = false;
                path.pop_back();
                curStop--;
            }
        }
    }
}

int main() {
    int n, m, pre, cur, k;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> cur;
            if (j > 0) {
                G[cur].push_back(Edge(cur, pre, i));
                G[pre].push_back(Edge(pre, cur, i));
            }
            pre = cur;
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> st >> dt;
        visited.resize(10000, false);
        minStop = INT32_MAX, minTrans = INT32_MAX, curStop = 0, curTrans = 0;
        ans.clear(), path.clear();
        dfs(st);
        cout << minStop << endl;
        int len = ans.size();
        for (int j = 0; j < len; ++j)
            printf("Take Line#%d from %04d to %04d.\n", ans[j].line, ans[j].u, ans[j].v);
    }

}