#include <bits/stdc++.h>

using namespace std;

int main() {
    int queryNum, courNum;
    cin >> queryNum >> courNum;
    map<string, vector<int>> stu;
    int index, num;
    string name;
    for (int i = 0; i < courNum; ++i) {
        cin >> index >> num;
        for (int j = 0; j < num; ++j) {
            cin >> name;
            stu[name].push_back(index);
        }
    }

    int n;
    vector<int> t;
    for (int i = 0; i < queryNum; ++i) {
        cin >> name;
        n = stu[name].size();
        cout << name << " " << n;
        if (n > 0) {
            t = stu[name];
            sort(t.begin(), t.end());
            for (int j = 0; j < n; ++j)
                cout << " " << t[j];
        }
        cout << endl;
    }
}