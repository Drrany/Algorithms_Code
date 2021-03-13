/* 
    注意：
        1. 如何重载set中的<运算符
        2. 结构体初始化的简便写法
        3. 如何删除set中的元素
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int num;
    int times;

    Node(int n, int t) : num(n), times(t) {}

    bool operator<(const Node &a) const {
        if (times != a.times) return times > a.times;
        return num < a.num;
    }
};


int main() {
    int n, k, num;
    cin >> n >> k;
    set<Node> ans;
    vector<int> table(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (i > 0) {
            cout << num << ":";
            int j = 0;
            for (auto it = ans.begin(); it != ans.end() && j < k; it++, j++)
                cout << " " << it->num;
            cout << "\n";
        }

        auto it = ans.find(Node(num, table[num]));
        if (it != ans.end()) ans.erase(it);
        table[num]++;
        ans.insert(Node(num, table[num]));
    }
}














using namespace std;

struct Node {
    int num;
    int times;

    Node(int i, int t) {
        num = i;
        times = t;
    }
};

bool cmp(const Node &a, const Node &b) {
    if (a.times != b.times) return a.times > b.times;
    return a.num < b.num;
}

int main() {
    int n, k, num, len = 0;
    cin >> n >> k;
    vector<Node> ans;
    int minTimes = INT32_MAX;
    vector<int> table(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (i > 0) {
            cout << num << ":";
            for (int j = 0; j < len; ++j)
                cout << " " << ans[j].num;
            cout << "\n";
        }

        table[num]++;
        // 当ans不足k个，或minTimes小于等于其时更新
        if (len < k || minTimes == INT32_MAX || minTimes <= table[num]) {
            // 在ans中找num
            int cnt = -1;
            for (int j = 0; j < len; ++j) {
                if (ans[j].num == num) {
                    cnt = j;
                    break;
                }
            }
            if (cnt == -1) { // 如果ans中无num
                if (len < k) { // 若ans小于3，直接添加
                    len++;
                    ans.emplace_back(num, table[num]);
                } else if (len == k && minTimes <= table[num]) { // 若ans等于k且有可能更新
                    // 从后向前找到第一个minTimes
                    for (int j = len - 1; j >= 0; --j) {
                        if (ans[j].times == minTimes) {
                            if ((table[num] > minTimes) || (table[num] == minTimes && num < ans[j].num)) {
                                ans[j] = Node(num, table[num]);
                                break;
                            }
                        }
                    }
                }
            } else // 如果ans中有num
                ans[cnt].times++;

            // 更新minTimes
            minTimes = INT32_MAX;
            for (int j = 0; j < len; ++j) {
                minTimes = min(minTimes, ans[j].times);
            }

            sort(ans.begin(), ans.end(), cmp);
        }

    }
}