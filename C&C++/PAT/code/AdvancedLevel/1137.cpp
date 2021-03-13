#include <bits/stdc++.h>
using namespace std;

struct Info {
    string id;
    int proScore = -1;
    int midScore = -1;
    int finalScore = -1;
    int score;
    bool valid = false;

    void calculate() {
        if (midScore > finalScore) {
            if (finalScore == -1) score = (int) (round((double) midScore * 0.4));
            else score = (int) round((double) midScore * 0.4 + (double) finalScore * 0.6);
        } else score = finalScore;
        if (proScore >= 200 && score >= 60) valid = true;
    }
};

bool cmp(const Info &a, const Info &b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

int main() {
    int p, m, n, score;
    string id;
    cin >> p >> m >> n;
    unordered_map<string, Info> mp;
    for (int i = 0; i < p; ++i) {
        cin >> id >> score;
        mp[id].proScore = score;
    }
    for (int i = 0; i < m; ++i) {
        cin >> id >> score;
        mp[id].midScore = score;
    }
    for (int i = 0; i < n; ++i) {
        cin >> id >> score;
        mp[id].finalScore = score;
        mp[id].calculate();
    }
    vector<Info> arr;
    for (auto &e:mp) {
        if (e.second.valid) {
            e.second.id = e.first;
            arr.push_back(e.second);
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    for (const auto &e:arr) {
        cout << e.id << " " << e.proScore << " " << e.midScore << " " << e.finalScore << " " << e.score << "\n";
    }
}