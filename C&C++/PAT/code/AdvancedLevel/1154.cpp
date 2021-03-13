// 判断图是否满足k-着色
// 本来使用bfs判断，但是超时了，看了别人的发现可以直接遍历每条边，判断边的两端顶点的着色是否相同。或者使用邻接表

#include <bits/stdc++.h>

using namespace std;
int G[10010][10010]{};
int color[10010]{};

struct Edge {
    int u, v;

    Edge(int iu, int iv) {
        u = iu, v = iv;
    }
};

bool canColor(vector<Edge> edges, int m) {
    int u, v;
    for (int i = 0; i < m; ++i) {
        u = edges[i].u, v = edges[i].v;
        if (color[u] == color[v])
            return false;
    }
    return true;
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    vector<Edge> edges;
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        edges.push_back(Edge(u, v));
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        set<int> colorNum;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &color[j]);
            colorNum.insert(color[j]);
        }
        if (canColor(edges, m))
            printf("%d-coloring\n", colorNum.size());
        else printf("No\n");
    }
}

// 方法2：使用邻接表
int main() {
    int n, m, u, v, k;
    cin >> n >> m;
    unordered_map<int, unordered_set<int>> adjList;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adjList[u].insert(v);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        vector<int> color(n);
        unordered_set<int> count;
        for (int j = 0; j < n; ++j) {
            cin >> color[j];
            count.insert(color[j]);
        }
        // u和邻接点的颜色不能相同
        bool can = true;
        for (u = 0; u < n && can; ++u) {
            unordered_set<int> adj = adjList[u];
            for (const auto &e:adj) {
                if (color[u] == color[e]) {
                    can = false;
                    break;
                }
            }
        }
        if (can) cout << count.size() << "-coloring\n";
        else cout << "No\n";
    }
}