#include <bits/stdc++.h>
using namespace std;

struct record {
    string plate;
    int hh, mm, ss;
    int sec;
    int in;

    record(const string &p, const string &times, const string &status) {
        plate = p;
        hh = stoi(times.substr(0, 2));
        mm = stoi(times.substr(3, 2));
        ss = stoi(times.substr(6, 2));
        sec = hh * 3600 + mm * 60 + ss;
        in = (status == "in") ? 1 : 0;
    }
};

bool cmp1(const record &a, const record &b) {
    if (a.plate != b.plate) return a.plate < b.plate;
    return a.sec < b.sec;
}

bool cmp2(const record &a, const record &b) {
    return a.sec < b.sec;
}

int main() {
    int n, k;
    cin >> n >> k;
    string plate, times, status;
    vector<record> arr;
    unordered_map<string, int> mp;
    vector<string> ans;
    int maxSec = 0;
    for (int i = 0; i < n; ++i) {
        cin >> plate >> times >> status;
        arr.emplace_back(plate, times, status);
    }
    sort(arr.begin(), arr.end(), cmp1);
    vector<record> valid;
    for (int i = 0; i < n; ++i) {
        if (arr[i].in == 1) {
            if (i < n - 1 && arr[i + 1].plate == arr[i].plate && arr[i + 1].in == 0) {
                valid.push_back(arr[i]);
                valid.push_back(arr[i + 1]);
                if (mp.find(arr[i].plate) == mp.end())
                    mp[arr[i].plate] = 0;
                mp[arr[i].plate] += arr[i + 1].sec - arr[i].sec;
                if (mp[arr[i].plate] > maxSec) {
                    ans.clear();
                    ans.push_back(arr[i].plate);
                    maxSec = mp[arr[i].plate];
                } else if (mp[arr[i].plate] == maxSec)
                    ans.push_back(arr[i].plate);
            }
        }
    }
    sort(valid.begin(), valid.end(), cmp2);
    int num = 0, be = 0, len = valid.size();
    for (int i = 0; i < k; ++i) {
        cin >> times;
        int sec = stoi(times.substr(0, 2)) * 3600 + stoi(times.substr(3, 2)) * 60 + stoi(times.substr(6));
        for (; be < len; ++be) {
            if (valid[be].sec <= sec) {
                if (valid[be].in) num++;
                else num--;
            } else break;
        }
        cout << num << "\n";
    }
    sort(ans.begin(), ans.end());
    for (const auto &e:ans)
        cout << e << " ";
    printf("%02d:%02d:%02d", maxSec / 3600, maxSec % 3600 / 60, maxSec % 3600 % 60);


}