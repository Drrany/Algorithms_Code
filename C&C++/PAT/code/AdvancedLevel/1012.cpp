#include <bits/stdc++.h>

using namespace std;

struct stu {
    string id;
    int c, m, e, a;
    int crank, mrank, erank, arank;
    int bestRank;
    char r;

    void findBest() {
        bestRank = min(crank, min(mrank, min(arank, erank)));
        if (bestRank == arank)
            r = 'A';
        else if (bestRank == crank)
            r = 'C';
        else if (bestRank == mrank)
            r = 'M';
        else r = 'E';
    }

};

bool cmpC(stu a, stu b) {
    return a.c > b.c;
}

bool cmpM(stu a, stu b) {
    return a.m > b.m;
}

bool cmpA(stu a, stu b) {
    return a.a > b.a;
}

bool cmpE(stu a, stu b) {
    return a.e > b.e;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<stu> s;
    for (int i = 0; i < n; ++i) {
        stu t;
        cin >> t.id >> t.c >> t.m >> t.e;
        t.a = (t.c + t.m + t.e) / 3;
        s.push_back(t);
    }

    sort(s.begin(), s.end(), cmpA);
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i].a != s[i - 1].a)
            s[i].arank = i + 1;
        else s[i].arank = s[i - 1].arank;
    }
    sort(s.begin(), s.end(), cmpC);
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i].c != s[i - 1].c)
            s[i].crank = i + 1;
        else s[i].crank = s[i - 1].crank;
    }
    sort(s.begin(), s.end(), cmpM);
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i].m != s[i - 1].m)
            s[i].mrank = i + 1;
        else s[i].mrank = s[i - 1].mrank;
    }
    sort(s.begin(), s.end(), cmpE);
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i].e != s[i - 1].e)
            s[i].erank = i + 1;
        else s[i].erank = s[i - 1].erank;
    }

    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        bool found = false;
        for (int j = 0; j < s.size(); ++j) {
            if (t == s[j].id) {
                found = true;
                s[j].findBest();
                cout << s[j].bestRank << " " << s[j].r << endl;
            }
        }
        if (!found)
            cout << "N/A" << endl;
    }


}