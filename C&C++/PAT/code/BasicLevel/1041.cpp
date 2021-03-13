#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 2001;

struct info {
    string reg;
    int test;
    int site;
};

int main() {
    int n, m;
    map<int, info> stu;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        info tmp;
        cin >> tmp.reg >> tmp.test >> tmp.site;
        stu[tmp.test] = tmp;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int query;
        cin >> query;
        cout << stu[query].reg << " " << stu[query].site << endl;
    }
}