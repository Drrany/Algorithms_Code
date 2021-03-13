#include <bits/stdc++.h>
using namespace std;
struct node {
    int addr, key, next;
};
node arr[100000]{};

void printList(const vector<node> &list) {
    int len = list.size();
    for (int i = 0; i < len; ++i) {
        printf("%05d %d ", list[i].addr, list[i].key);
        if (i < len - 1) printf("%05d\n", list[i + 1].addr);
        else printf("-1\n");
    }
}

int main() {
    int n, st, addr, key, next;
    cin >> st >> n;
    for (int i = 0; i < n; ++i) {
        cin >> addr >> key >> next;
        arr[addr].next = next, arr[addr].addr = addr, arr[addr].key = key;
    }
    vector<node> valid, removed;
    unordered_set<int> kset;
    while (st != -1) {
        if (kset.count(abs(arr[st].key)) == 0) {
            kset.insert(abs(arr[st].key));
            valid.push_back(arr[st]);
        } else removed.push_back(arr[st]);
        st = arr[st].next;
    }

    printList(valid);
    printList(removed);

}