#include <bits/stdc++.h>

using namespace std;

struct info {
    string name;
    string id;
    int score = -1;
};


int main() {
    int n;
    cin >> n;
    info female[101]{};
    info male[101]{};
    int fcount = 0, mcount = 0;
    for (int i = 0; i < n; ++i) {
        info t;
        char flag;
        cin >> t.name >> flag >> t.id >> t.score;
        if (flag == 'M') {
            male[t.score] = t;
            mcount++;
        } else {
            female[t.score] = t;
            fcount++;
        }
    }
    int fmax, mmin;
    if (fcount == 0)
        cout << "Absent" << endl;
    else {
        int i = 100;
        while (true) {
            if (female[i--].score != -1) {
                cout << female[i + 1].name << " " << female[i + 1].id << endl;
                fmax = female[i + 1].score;
                break;
            }
        }
    }
    if (mcount == 0)
        cout << "Absent" << endl;
    else {
        int i = 0;
        while (true) {
            if (male[i++].score != -1) {
                cout << male[i - 1].name << " " << male[i - 1].id << endl;
                mmin = male[i - 1].score;
                break;
            }
        }
    }
    if (mcount == 0 || fcount == 0)
        cout << "NA" << endl;
    else
        cout << fmax - mmin;

}