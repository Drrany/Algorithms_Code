/*
 * 注意点：
 *      1. b找同性朋友A时，A不能是g。A找同性朋友B时，B不能是b
 *      2. 输出时候要以4位数的方式输出，所以要%04d
 *      3. 要处理-0000和0000无法分辨性别的问题，所以用string接收
 * */
#include <bits/stdc++.h>
using namespace std;

struct ansNode {
    int first, second;

    ansNode(int c, int d) {
        first = abs(c);
        second = abs(d);
    }
};

bool cmp(const ansNode &a, const ansNode &b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int G[310][310]{};

int main() {
    int n, m, iu, iv, count = 0, k, a, b;
    cin >> n >> m;
    string u, v;
    unordered_map<int, int> mp; // id-数组下标
    unordered_map<int, int> in_mp; // 数组下标-id
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        int numu = stoi(u), numv = stoi(v);
        if (mp.find(numu) == mp.end()) {
            in_mp[count] = numu;
            mp[numu] = count++;
        }
        if (mp.find(numv) == mp.end()) {
            in_mp[count] = numv;
            mp[numv] = count++;
        }
        iu = mp[numu], iv = mp[numv];
        if (u.size() != v.size()) G[iu][iv] = G[iv][iu] = -1;
        else G[iu][iv] = G[iv][iu] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        int ia = mp[a], ib = mp[b];
        // 找出所有和ia相关联的同性别人，这个人不能是ib
        vector<int> connectA;
        for (int j = 0; j < count; ++j) {
            if (G[ia][j] == 1 && j != ib) connectA.push_back(j);
        }
        // 找出所有和ib相关联的同性别人，这个人不能是ia
        vector<int> connectB;
        for (int j = 0; j < count; ++j) {
            if (G[ib][j] == 1 && j != ia) connectB.push_back(j);
        }
        int tg = (a * b > 0) ? 1 : -1;
        vector<ansNode> ans;
        for (const auto &c:connectA) {
            for (const auto &d:connectB) {
                if (c != d && G[c][d] == tg)
                    ans.emplace_back(in_mp[c], in_mp[d]);
            }
        }
        int len = ans.size();
        cout << len << "\n";
        if (len > 0) {
            sort(ans.begin(), ans.end(), cmp);
            for (const auto &e:ans)
                printf("%04d %04d\n", e.first, e.second);
        }
    }

}