/*
 * 注意：
 *      1. 主元不仅要在正确位置，还需要大于左侧所有元素和小于右侧所有元素（只要满足其中一个，另一个也可满足）
 *      2. 有一个格式错误，可能是因为不存在主元时，需要输出一个换行，在最后加一个换行就可以了
 * */

#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> maxLeft(n); // maxLeft[i]表示第i个元素左侧最大的值
    maxLeft[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (i > 0) maxLeft[i] = max(maxLeft[i - 1], arr[i - 1]);
    }
    vector<int> right(arr);
    sort(right.begin(), right.end());
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (right[i] == arr[i] && right[i] > maxLeft[i])
            ans.push_back(right[i]);
    }
    int len = ans.size();
    cout << len << "\n";
    for (int i = 0; i < len; ++i) {
        cout << ans[i];
        if (i < len - 1) cout << " ";
    }
    cout << "\n";
}












