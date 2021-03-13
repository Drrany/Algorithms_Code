/* 
    重做
 */
#include <bits/stdc++.h>

using namespace std;


bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N, m, n;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);
    n = sqrt(N);
    for (; n > 0; --n) {
        if (N % n == 0) {
            m = N / n;
            break;
        }
    }
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    int up = 0, down = m - 1, left = 0, right = n - 1;
    int k = 0;
    while (true) {
        // 向右移动
        for (int i = left; i <= right; ++i)
            matrix[up][i] = arr[k++];
        up++;
        if (up > down) break;
        // 向下移动
        for (int i = up; i <= down; ++i)
            matrix[i][right] = arr[k++];
        right--;
        if (left > right) break;
        // 向左移动
        for (int i = right; i >= left; --i)
            matrix[down][i] = arr[k++];
        down--;
        if (up > down) break;
        // 向上移动
        for (int i = down; i >= up; --i)
            matrix[i][left] = arr[k++];
        left++;
        if (left > right) break;
    }
    for (const auto &vi:matrix) {
        int len = vi.size();
        for (int i = 0; i < len; ++i) {
            cout << vi[i];
            if (i < len - 1) cout << " ";
        }
        cout << "\n";
    }


}












