#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    vector<string> fw(m + 1);
    unordered_set<string> winSet;
    vector<string> winList;
    for (int i = 1; i <= m; ++i)
        cin >> fw[i];
    while (s <= m) {
        if (winSet.find(fw[s]) == winSet.end()) {
            winList.push_back(fw[s]);
            winSet.insert(fw[s]);
            s += n;
        } else s++;
    }
    if (winSet.empty())
        cout << "Keep going...";
    else {
        for (const auto &e:winList)
            cout << e << "\n";
    }


}