#include <bits/stdc++.h>
using namespace std;
int k;

struct node {
    int addr, next, data, lev, order;

    node() {}

    node(int a, int n, int d) {
        addr = a, next = n, data = d;
        if (data < 0) lev = 1;
        else if (data >= 0 && data <= k) lev = 2;
        else lev = 3;
    }
};

node arr[100000]{};


bool cmp(const node &a, const node &b) {
    if (a.lev != b.lev) return a.lev < b.lev;
    return a.order < b.order;
}

int main() {
    int st, n, addr, next, data;
    cin >> st >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> addr >> data >> next;
        arr[addr] = node(addr, next, data);
    }
    vector<node> valid;
    int count = 0;
    while (st != -1) {
        valid.push_back(arr[st]);
        valid[count].order = count;
        count++;
        st = arr[st].next;
    }
    sort(valid.begin(), valid.end(), cmp);
    for (int i = 0; i < count; ++i) {
        printf("%05d %d ", valid[i].addr, valid[i].data);
        if (i < count - 1) printf("%05d\n", valid[i + 1].addr);
        else cout << "-1\n";
    }


}