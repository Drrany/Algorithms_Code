#include <bits/stdc++.h>

using namespace std;

struct stu {
    string id;
    int d;
    int c;
    int sum;
    int level;
};

bool cmp(stu a, stu b) {
    if (a.level != b.level)
        return a.level > b.level;
    else if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.d != b.d)
        return a.d > b.d;
    else return a.id < b.id;
}

int main() {
    int n, l, h;
    cin >> n >> l >> h;
    vector<stu> s;
    for (int i = 0; i < n; ++i) {
        stu tmp;
        cin >> tmp.id >> tmp.d >> tmp.c;
        tmp.sum = tmp.d + tmp.c;
        if (tmp.d >= l && tmp.c >= l) {
            if (tmp.d >= h && tmp.c >= h)
                tmp.level = 4;
            else if (tmp.d >= h && tmp.c < h)
                tmp.level = 3;
            else if (tmp.d < h && tmp.c < h && tmp.d >= tmp.c)
                tmp.level = 2;
            else
                tmp.level = 1;
            s.push_back(tmp);
        }
    }

    sort(s.begin(), s.end(), cmp);
    cout << s.size() << endl;
    for (int i = 0; i < s.size(); ++i)
        cout << s[i].id << " " << s[i].d << " " << s[i].c << endl;


}