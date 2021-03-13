#include <bits/stdc++.h>

using namespace std;

struct info {
    string name, id;
    int grade;

    info(string n, string i, int g) {
        name = n, id = i, grade = g;
    }
};

bool cmp(const info &a, const info &b) {
    return a.grade > b.grade;
}

int main() {
    int n, grade;
    string name, id;
    cin >> n;
    vector<info> stu;
    for (int i = 0; i < n; ++i) {
        cin >> name >> id >> grade;
        stu.emplace_back(name, id, grade);
    }
    sort(stu.begin(), stu.end(), cmp);
    int down, up, count = 0;
    cin >> down >> up;
    for (const auto &e:stu) {
        if (e.grade >= down && e.grade <= up) {
            cout << e.name << " " << e.id << "\n";
            count++;
        }
        else if (e.grade < down)
            break;
    }
    if (count == 0) cout << "NONE";
}










