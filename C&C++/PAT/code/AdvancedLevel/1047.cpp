#include <bits/stdc++.h>

using namespace std;

int main() {
    int stuNum, courseNum;
    cin >> stuNum >> courseNum;
    map<int, vector<string>> cs;
    string name;
    name.resize(5);
    int n, index;
    for (int i = 0; i < stuNum; ++i) {
        scanf("%s %d", &name[0], &n);
        for (int j = 0; j < n; ++j) {
            cin >> index;
            cs[index].push_back(name);
        }
    }

    vector<string> v;
    int len;
    for (int i = 1; i <= courseNum; ++i) {
        v = cs[i];
        len = v.size();
        printf("%d %d", i, len);
        if (len > 0) {
            sort(v.begin(), v.end());
            for (int j = 0; j < len; ++j)
                printf("\n%s", v[j].c_str());
        }
        printf("\n");
    }
}