#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 100010;

struct Node {
    int next;   // 指向下一个结点在数组中的下标
    bool flag;  // 结点是否在第一条链表中出现
};
Node nodes[MAXSIZE]{};

int main() {
    int f1, f2, n;
    cin >> f1 >> f2 >> n;
    int cur, next;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> cur >> c >> next;
        nodes[cur].next = next;
    }
    int tmp = f1;
    while (tmp != -1) {
        nodes[tmp].flag = true;
        tmp = nodes[tmp].next;
    }

    tmp = f2;
    while (tmp != -1) {
        if (nodes[tmp].flag) {
            printf("%05d", tmp);
            break;
        }
        tmp = nodes[tmp].next;
    }
    if (tmp == -1)
        cout << tmp;

}