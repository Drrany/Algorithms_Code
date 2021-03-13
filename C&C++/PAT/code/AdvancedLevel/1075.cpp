#include <bits/stdc++.h>

using namespace std;
vector<int> ps;

struct info {
    int id, solNum, total, canShow = 0, rank;
    vector<int> score;

    info() { id = -1; }

    info(int i, int k) {
        id = i;
        score.resize(k + 1, -2);
    }

    void calcu(int k) {
        total = 0, solNum = 0;
        for (int i = 1; i <= k; ++i) {
            if (score[i] >= 0) {
                canShow = 1;
                total += score[i];
                if (score[i] == ps[i])
                    solNum++;
            }
        }
    }
};

vector<info> arr(10010);

bool cmp(const info &a, const info &b) {
    if (a.canShow != b.canShow) return a.canShow > b.canShow;
    if (a.total != b.total) return a.total > b.total;
    if (a.solNum != b.solNum) return a.solNum > b.solNum;
    return a.id < b.id;
}

int main() {
    int n, k, m, id, no, sco;
    cin >> n >> k >> m;
    ps.resize(k + 1);
    for (int i = 1; i <= k; ++i)
        cin >> ps[i];
    for (int i = 0; i < m; ++i) {
        cin >> id >> no >> sco;
        if (arr[id].id == -1)
            arr[id] = info(id, k);
        arr[id].score[no] = max(arr[id].score[no], sco);
    }
    for (int i = 0; i < 10010; ++i) {
        if (arr[i].id != -1)
            arr[i].calcu(k);
    }

    sort(arr.begin(), arr.end(), cmp);
    arr[0].rank = 1;
    int i = 1;
    while (arr[i].canShow == 1) {
        if (arr[i].total == arr[i - 1].total)
            arr[i].rank = arr[i - 1].rank;
        else arr[i].rank = i + 1;
        i++;
    }

    for (int j = 0; j < i; ++j) {
        printf("%d %05d %d", arr[j].rank, arr[j].id, arr[j].total);
        vector<int> sc = arr[j].score;
        for (int l = 1; l <= k; ++l) {
            if (sc[l] >= 0) cout << " " << sc[l];
            else if (sc[l] == -1) cout << " 0";
            else cout << " -";
        }
        cout << endl;
    }
}










