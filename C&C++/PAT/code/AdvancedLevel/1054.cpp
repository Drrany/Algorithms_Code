#include <bits/stdc++.h>

using namespace std;

// 不使用map的做法：两两抵消
int main() {
    int m, n;
    cin >> m >> n;
    int num;
    int count = 0, ans;
    for (int i = 0; i < n * m; ++i) {
        cin >> num;
        if (count == 0) {
            ans = num;
            count++;
        } else if (ans == num)
            count++;
        else count--;
    }
    cout << ans;

}

int main() {
    int m, n;
    cin >> m >> n;
    map<int, int, greater<> > count;
    int num;
    int maxCount = 0, ans;
    for (int i = 0; i < n * m; ++i) {
        cin >> num;
        count[num]++;
        if (count[num] > maxCount) {
            maxCount = count[num];
            ans = num;
        }
    }
    cout << ans;

}