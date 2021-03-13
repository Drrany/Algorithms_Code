#include <bits/stdc++.h>

using namespace std;

struct info {
    string id, name;
    int grade;

    info(string i, string n, int g) {
        id = i, name = n, grade = g;
    }
};

bool cmp1(const info &a, const info &b) {
    return a.id < b.id;
}

bool cmp2(const info &a, const info &b) {
    return (a.name != b.name) ? a.name < b.name : a.id < b.id;
}

bool cmp3(const info &a, const info &b) {
    return (a.grade != b.grade) ? a.grade < b.grade : a.id < b.id;
}


int main() {
    int n, c, grade;
    string id, name;
    cin >> n >> c;
    vector<info> arr;
    for (int i = 0; i < n; ++i) {
        cin >> id >> name >> grade;
        arr.emplace_back(id, name, grade);
    }
    if (c == 1)
        sort(arr.begin(), arr.end(), cmp1);
    else if (c == 2)
        sort(arr.begin(), arr.end(), cmp2);
    else sort(arr.begin(), arr.end(), cmp3);

    for (int i = 0; i < n; ++i)
        cout << arr[i].id << " " << arr[i].name << " " << arr[i].grade << "\n";

}