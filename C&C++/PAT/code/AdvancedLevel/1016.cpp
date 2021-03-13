// 如何根据每小时不同计算花费！！！！
#include <bits/stdc++.h>

using namespace std;

struct record {
    string name;
    int day, hour, minute;
    int mi;
    int status;

    record(string n, string time, string st) {
        name = n;
        day = stoi(time.substr(0, 2));
        hour = stoi(time.substr(3, 2));
        minute = stoi(time.substr(6));
        mi = day * 60 * 24 + hour * 60 + minute;
        if (st == "on-line") status = 0;
        else status = 1;
    }
};


bool cmp(const record &a, const record &b) {
    if (a.name != b.name) return a.name < b.name;
    if (a.day != b.day) return a.day < b.day;
    return a.mi < b.mi;
}

int rate[24];

double cal(record &a, const record &b) {
    double res = 0;
    while (a.day != b.day || a.hour != b.hour || a.minute != b.minute) {
        a.minute++;
        res += rate[a.hour];
        if (a.minute == 60) {
            a.minute = 0;
            a.hour++;
        }
        if (a.hour == 24) {
            a.hour = 0;
            a.day++;
        }
    }
    return res;
}

int main() {
    for (int i = 0; i < 24; ++i)
        cin >> rate[i];
    int n;
    cin >> n;
    string name, time, month, st;
    vector<record> arr;
    for (int i = 0; i < n; ++i) {
        cin >> name >> time >> st;
        if (i == 0) month = time.substr(0, 2);
        arr.emplace_back(name, time.substr(3), st);
    }
    sort(arr.begin(), arr.end(), cmp);
    vector<record> valid;
    int i = 0;
    while (i < n) {
        if (i < n - 1 && (arr[i].name == arr[i + 1].name) && (arr[i].status == 0) && (arr[i + 1].status == 1)) {
            valid.push_back(arr[i++]);
            valid.push_back(arr[i++]);
        } else i++;
    }
    int len = valid.size();
    i = 0;
    while (i < len) {
        name = valid[i].name;
        cout << name << " " << month << endl;
        double sum = 0.0, cur;
        while (valid[i].name == name) {
            record a = valid[i++], b = valid[i++];
            printf("%02d:%02d:%02d %02d:%02d:%02d %d ", a.day, a.hour, a.minute, b.day, b.hour, b.minute,
                   b.mi - a.mi);
            // 计算费用
            cur = cal(a, b) / 100.0;
            printf("$%.2f\n", cur);
            sum += cur;
        }
        printf("Total amount: $%.2f\n", sum);
    }
}