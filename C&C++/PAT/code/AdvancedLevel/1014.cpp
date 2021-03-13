// 重做
#include <bits/stdc++.h>

using namespace std;

struct window {
    queue<int> que;
    int firstTime;  // 队伍第一个人完成服务的时间
    int endTime;    // 队伍最后一个人完成服务的时间
    window() {
        firstTime = endTime = 0;
    }
};

int main() {
    int n, m, k, q, t;
    int limit = (17 - 8) * 60;
    cin >> n >> m >> k >> q;
    vector<int> process(k);
    vector<int> finished(k, 0);
    vector<window> ws(n);
    vector<bool> sorry(k, false);
    for (int i = 0; i < k; ++i) {
        cin >> process[i];
        int target;
        if (i < n * m) { // 前n*m个人直接进入队伍
            target = i % n; // 进入的窗口
        } else { //对于后面的人，找最早完成的一个队伍
            int minTime = INT32_MAX;
            for (int j = 0; j < n; ++j) {
                if (ws[j].firstTime < minTime) {
                    minTime = ws[j].firstTime;
                    target = j;
                }
            }
            ws[target].que.pop();   // 第一个人出队
        }
        ws[target].que.push(i); // 第i个人入队
        if (ws[target].endTime >= limit) sorry[i] = true;
        finished[i] = ws[target].endTime + process[i];
        int top = ws[target].que.front();
        ws[target].firstTime = finished[top];
        ws[target].endTime = finished[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> t;
        if (sorry[t - 1]) cout << "Sorry\n";
        else printf("%02d:%02d\n", finished[t - 1] / 60 + 8, finished[t - 1] % 60);
    }

}