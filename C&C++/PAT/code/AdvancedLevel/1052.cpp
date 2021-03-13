#include <bits/stdc++.h>

using namespace std;

struct node {
    int key, addr, next;
    bool valid = false;

    node() {};

    node(int k, int a, int n) {
        key = k, addr = a, next = n;
    }
};

bool cmp(const node &a, const node &b) {
    if (a.valid != b.valid) return a.valid > b.valid;
    return a.key < b.key;
}

node arr[100000]{};

int main() {
    int n, st, addr, next, key;
    cin >> n >> st;
    for (int i = 0; i < n; ++i) {
        cin >> addr >> key >> next;
        arr[addr] = node(key, addr, next);
    }
    int count = 0;
    while (st != -1) {
        count++;
        arr[st].valid = true;
        st = arr[st].next;
    }
    if (count == 0)
        printf("0 -1\n");
    else {
        sort(arr, arr + 100000, cmp);
        printf("%d %05d\n", count, arr[0].addr);
        for (int i = 0; i < count; ++i) {
            if (i < count - 1)
                printf("%05d %d %05d\n", arr[i].addr, arr[i].key, arr[i + 1].addr);
            else
                printf("%05d %d -1\n", arr[i].addr, arr[i].key);
        }
    }
}
