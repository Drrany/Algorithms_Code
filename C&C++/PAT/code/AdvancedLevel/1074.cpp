#include <bits/stdc++.h>

using namespace std;
struct node {
    int addr, next, value;
};
node G[100000]{};

int main() {
    int st, n, k, addr, next, value;
    cin >> st >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> addr >> value >> next;
        G[addr].addr = addr, G[addr].next = next, G[addr].value = value;
    }
    vector<node> valid;
    while (st != -1) {
        valid.push_back(G[st]);
        st = G[st].next;
    }
    int len = valid.size();
    for (int i = 0; i < len; i += k) {
        if (i + k <= len)
            reverse(valid.begin() + i, valid.begin() + i + k);
    }
    for (int i = 0; i < len; ++i) {
        if (i < len - 1)
            printf("%05d %d %05d\n", valid[i].addr, valid[i].value, valid[i + 1].addr);
        else printf("%05d %d -1", valid[i].addr, valid[i].value);
    }

}