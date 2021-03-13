#include <bits/stdc++.h>

using namespace std;

int deal(string str, int d) {
    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if ((str[i] - '0') == d)
            count++;
    }
    if (count == 0)
        return 0;
    string res;
    res.append(count, char(d + '0'));
    return stoi(res);
}


int main() {
    string a, b;
    int da, db;
    cin >> a >> da >> b >> db;
    int pa = deal(a, da);
    int pb = deal(b, db);
    int sum = pa + pb;
    cout << sum;
}