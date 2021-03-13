/* 
    这道题主要是超时问题，改了几个点之后可以过了：
        1. 用unordered_map代替map
        2. 用'\n'代替endl
        3. 在排序函数中使用
        4. scanf和printf代替cin和cout，但是字符串类型难以用其代替
    此外在使用getline之前，假如已经用过了cin，在该语句后加一个cin.ignore()，可以忽略后面的换行符，让getline正常读入

 */
#include <bits/stdc++.h>

using namespace std;

struct Info {
    string ori;
    char level; 
    string site;
    string date;
    int score;

    Info() {}

    // 引用传参比较快
    Info(const string &o, const int &s) {
        ori = o;
        level = o[0];
        site = o.substr(1, 3);
        date = o.substr(4, 6);
        score = s;
    }
};


struct SN {
    string site;
    int num;

    SN(const string &is, const int &in) {
        site = is, num = in;
    };
};

// 引用传参速度比较快
bool cmp1(const Info &a, const Info &b) {
    if (a.score != b.score)
        return a.score > b.score;
    return a.ori < b.ori;
}

bool cmp2(const SN &a, const SN &b) {
    if (a.num != b.num)
        return a.num > b.num;
    else return a.site < b.site;
}

int main() {
    // 关闭cin和cout的同步
    ios::sync_with_stdio(false);
    int n, m, score;
    cin >> n >> m;
    cin.ignore();
    string ori;
    vector<Info> stu;
    for (int i = 0; i < n; ++i) {
        cin >> ori >> score;
        cin.ignore();
        stu.push_back(Info(ori, score));
    }
    string query, site, date;
    for (int i = 1; i <= m; ++i) {
        getline(cin, query);
        cout << "Case " << i << ": " << query << "\n";
        if (query[0] == '1') {
            vector<Info> arr;
            int len = 0;
            for (int j = 0; j < n; ++j) {
                if (stu[j].level == query[2]) {
                    arr.push_back(stu[j]);
                    len++;
                }
            }
            if (len == 0)
                cout << "NA\n";
            else {
                sort(arr.begin(), arr.end(), cmp1);
                for (const auto &e:arr) {
                    cout << e.ori << " " << e.score << "\n";
                }
            }
        } else if (query[0] == '2') {
            string site = query.substr(2, 3);
            int total = 0, len = 0;
            for (int j = 0; j < n; ++j) {
                if (stu[j].site == site) {
                    total += stu[j].score;
                    len++;
                }
            }
            if (len == 0)
                cout << "NA\n";
            else
                cout << len << " " << total << "\n";
        } else {
            date = query.substr(2, 6);
            unordered_map<string, int> mp;
            for (int j = 0; j < n; ++j) {
                if (stu[j].date == date) {
                    if (mp.find(stu[j].site) == mp.end())
                        mp[stu[j].site] = 1;
                    else
                        mp[stu[j].site]++;
                }
            }
            if (mp.size() == 0)
                cout << "NA\n";
            else {
                vector<SN> arr;
                for (const auto &e:mp) {
                    arr.emplace_back(e.first, e.second);
                }
                sort(arr.begin(), arr.end(), cmp2);
                for (const auto &e:arr) {
                    cout << e.site << " " << e.num << "\n";
                }
            }
        }
    }

}