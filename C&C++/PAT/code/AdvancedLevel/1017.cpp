#include <bits/stdc++.h>

using namespace std;
int limit = (17 - 8) * 3600;

struct record {
    int arrive;
    int cost;
    bool valid;

    record(int a, int c) {
        arrive = a, cost = c;
        if (arrive > limit) valid = false;
        else valid = true;
    }
};

bool cmp(const record &a, const record &b) {
    return a.arrive < b.arrive;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> finished(k, 0); // finished[i]表示第i个窗口的人结束时间
    vector<int> wait(n, 0);
    vector<record> arr;
    int cost;
    string times;
    for (int i = 0; i < n; ++i) {
        cin >> times >> cost;
        int cur = (stoi(times.substr(0, 2)) - 8) * 3600 + (stoi(times.substr(3, 2))) * 60 + (stoi(times.substr(6)));
        arr.emplace_back(cur, cost * 60);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; ++i) {
        int cur = arr[i].arrive;
        if (cur < 0) { // 如果到早了
            wait[i] = -cur;
            cur = 0;
        }
        // 找当前结束时间最早的窗口
        int target = 0, minTime = INT32_MAX;
        for (int j = 0; j < k; ++j) {
            if (finished[j] < minTime) {
                minTime = finished[j];
                target = j;
            }
        }
        if (cur >= finished[target]) { // 如果到达时间晚于完成时间
            finished[target] = cur + arr[i].cost;
        } else {
            wait[i] += finished[target] - cur;
            finished[target] += arr[i].cost;
        }

    }
    int count = 0;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i].valid) {
            count++;
            sum += wait[i];
        }
    }
    printf("%.1f", sum / count / 60);
}