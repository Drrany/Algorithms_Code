#include <bits/stdc++.h>

using namespace std;
int lowLine, highLine;

struct info {
    string id;
    int vir, tal, total;
    int level;

    info(string d, int v, int t) {
        id = d, vir = v, tal = t, total = v + t;
        if (v >= highLine && t >= highLine) level = 1;
        else if (v >= highLine && t >= lowLine) level = 2;
        else if (v >= t && t >= lowLine) level = 3;
        else level = 4;
    }
};

bool cmp(const info &a, const info &b) {
    if (a.level != b.level) return a.level < b.level;
    if (a.total != b.total) return a.total > b.total;
    if (a.vir != b.vir) return a.vir > b.vir;
    return a.id < b.id;
}

int main() {
    int n, v, t;
    string id;
    cin >> n >> lowLine >> highLine;
    vector<info> per;
    for (int i = 0; i < n; ++i) {
        cin >> id >> v >> t;
        if (v >= lowLine && t >= lowLine)
            per.emplace_back(id, v, t);
    }
    int len = per.size();
    cout << len << "\n";
    if (len > 0) {
        sort(per.begin(), per.end(), cmp);
        for (const auto &e:per)
            cout << e.id << " " << e.vir << " " << e.tal << "\n";
    }
}








