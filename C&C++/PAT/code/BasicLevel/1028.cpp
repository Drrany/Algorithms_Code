#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 1001;

struct person {
    string name;
    int year;
    int month;
    int day;
};

bool isLegal(person t) {
    if (t.year < 1814 || t.year > 2014)
        return false;
    else if (t.year == 1814 && t.month < 9)
        return false;
    else if (t.year == 1814 && t.month == 9 && t.day < 6)
        return false;
    else if (t.year == 2014 && t.month > 9)
        return false;
    else if (t.year == 2014 && t.month == 9 && t.day > 6)
        return false;
    return true;
}

bool cmp(person a, person b) {
    if (a.year > b.year)
        return true;
    else if (a.year == b.year && a.month > b.month)
        return true;
    else if (a.year == b.year && a.month == b.month && a.day > b.day)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<person> res;
    for (int i = 0; i < n; ++i) {
        person tmp;
        cin >> tmp.name;
        scanf("%d/%d/%d", &tmp.year, &tmp.month, &tmp.day);
        if (isLegal(tmp))
            res.push_back(tmp);
    }
    int num = res.size();
    cout << num;
    if (num > 0) {
        sort(res.begin(), res.end(), cmp);
        cout << " " << res[num - 1].name << " " << res[0].name;
    }

}