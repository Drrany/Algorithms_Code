// 用并查集再做一遍
#include <bits/stdc++.h>

using namespace std;

using namespace std;
const int maxn = 10000;
int est[maxn]{}, area[maxn]{};
vector<int> father(maxn, -1);
bool in[maxn]{};

struct node
{
    int num, id;
    double avgS = 0.0, avgA = 0.0;

    node(const vector<int> &re)
    {
        num = re.size();
        id = INT32_MAX;
        for (const auto &e : re)
        {
            id = min(e, id);
            avgS += est[e];
            avgA += area[e];
        }
        avgS /= (double)num;
        avgA /= (double)num;
    }
};

int findFather(int u)
{
    if (father[u] == -1)
        return u;
    return findFather(father[u]);
}

bool cmp(const node &a, const node &b)
{
    if (a.avgA != b.avgA)
        return a.avgA > b.avgA;
    return a.id < b.id;
}

int main()
{
    int n, id, fid, mid, k, cid, f1, f2, f3;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> id >> fid >> mid;
        in[id] = true;
        if (fid != -1)
        {
            in[fid] = true;
            f1 = findFather(id);
            f2 = findFather(fid);
            if (f1 != f2)
                father[f1] = f2;
        }
        if (mid != -1)
        {
            in[mid] = true;
            f1 = findFather(id);
            f3 = findFather(mid);
            if (f1 != f3)
                father[f1] = f3;
        }
        cin >> k;
        f1 = findFather(id);
        for (int j = 0; j < k; ++j)
        {
            cin >> cid;
            in[cid] = true;
            f3 = findFather(cid);
            if (f1 != f3)
                father[f3] = f1;
        }
        cin >> est[id] >> area[id];
    }
    unordered_map<int, vector<int>> mp; // 同一个father对应的人
    for (int i = 0; i < maxn; ++i)
    {
        if (in[i])
        {
            int f = findFather(i);
            mp[f].push_back(i);
        }
    }
    vector<node> ans;
    for (const auto &vi : mp)
        ans.emplace_back(vi.second);
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end(), cmp);
    for (const auto &a : ans)
        printf("%04d %d %.3f %.3f\n", a.id, a.num, a.avgS, a.avgA);
}