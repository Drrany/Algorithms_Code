#include <bits/stdc++.h>

using namespace std;
vector<set<int>> G;
bool visited[10010]{};
int n, maxDepth = 0;

void dfs(int v) {
    set<int> tmp = G[v];
    for (auto i = tmp.begin(); i != tmp.end(); ++i) {
        if (!visited[*i]) {
            visited[*i] = true;
            dfs(*i);
        }
    }
}

void dfs2(int v, int depth, vector<int> &dep) {
    if (depth > maxDepth) {
        dep = vector<int>();
        dep.push_back(v);
        maxDepth = depth;
    } else if (depth == maxDepth)
        dep.push_back(v);
    set<int> tmp = G[v];
    for (auto i = tmp.begin(); i != tmp.end(); ++i) {
        if (!visited[*i]) {
            visited[*i] = true;
            dfs2(*i, depth + 1, dep);
        }
    }

}

int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i)
        G.emplace_back();
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }
    // 判断是否连通
    // 计算components
    int count = 0;
    fill(visited, visited + n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            count++;
            visited[i] = true;
            dfs(i);
        }
    }
    if (count > 1) {
        printf("Error: %d components", count);
        return 0;
    }
    // 从顶点1开始遍历，求最深的点
    vector<int> sa;
    fill(visited, visited + n + 1, false);
    dfs2(1, 1, sa);
    // 从dep中的一个任一顶点遍历，求能到达的最深的点
    vector<int> sb;
    fill(visited, visited + n + 1, false);
    maxDepth = 0;
    dfs2(sa[0], 1, sb);

    set<int> ans;
    ans.insert(sa.begin(), sa.end());
    ans.insert(sb.begin(), sb.end());
    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << endl;
}