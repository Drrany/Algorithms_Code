#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 2001;

struct stu {
    string name;
    string id;
    int score = -1;
};

int main() {
    int n;
    stu stus[101];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        stu tmp;
        cin >> tmp.name >> tmp.id >> tmp.score;
        stus[tmp.score] = tmp;
    }
    int i = 100;
    while (true) {
        if (stus[i].score != -1) {
            cout << stus[i].name << " " << stus[i].id << endl;
            break;
        }
        i--;
    }
    i = 0;
    while (true) {
        if (stus[i].score != -1) {
            cout << stus[i].name << " " << stus[i].id;
            break;
        }
        i++;
    }

}