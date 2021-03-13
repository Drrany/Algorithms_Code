#include <bits/stdc++.h>

using namespace std;

int G[2020][2020]{};
unordered_map<string, int> mp;
unordered_map<int, string> mp2;

struct node {
    int num;
    string head;

    node(int n, string h) {
        num = n, head = h;
    }
};

bool cmp(const node &a, const node &b) {
    return a.head < b.head;
}

void dfs(vector<bool> &visited, vector<int> &st, int n, int u) {
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && G[u][i] != 0) {
            visited[i] = true;
            st.push_back(i);
            dfs(visited, st, n, i);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    string name1, name2;
    int w, count = 0, index1, index2;
    vector<int> aw(2020, 0);
    for (int i = 0; i < n; ++i) {
        cin >> name1 >> name2 >> w;
        if (mp.find(name1) == mp.end())
            mp[name1] = count++;
        if (mp.find(name2) == mp.end())
            mp[name2] = count++;
        index1 = mp[name1], index2 = mp[name2];
        aw[index1] += w, aw[index2] += w;
        G[index1][index2] = 1;
        G[index2][index1] = 1;
    }
    for (auto it:mp)
        mp2[it.second] = it.first;

    vector<node> ans;
    vector<bool> visited(count, false);
    for (int i = 0; i < count; ++i) {
        // 计算包括i的连通分量
        if (visited[i]) continue;
        vector<int> com;
        com.push_back(i);
        visited[i] = true;
        dfs(visited, com, count, i);
        int len = com.size();
        if (len >= 3) {
            int head = com[0];
            int weight = 0;
            for (int j = 0; j < len; ++j) {
                weight += aw[com[j]] / 2;
                if (aw[com[j]] > aw[head])
                    head = com[j];
            }
            if (weight > k)
                ans.emplace_back(len, mp2[head]);
        }
    }
    int len = ans.size();
    cout << len << endl;
    if (len > 0) {
        sort(ans.begin(), ans.end(), cmp);
        for (auto it:ans)
            cout << it.head << " " << it.num << endl;
    }

}