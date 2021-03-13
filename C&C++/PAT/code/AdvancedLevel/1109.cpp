#include <bits/stdc++.h>
/* n个人排成k排。规则：
 *      1. 每排有n/k个人，向下取整，多余的人站在最后一排
 *      2. 后排的人不能比前排的人矮
 *      3. 每排里，最高的人站在中间的位置(m/2+1)，m为这排的总人数，m/2向下取整
 *      4. 每排里，其他人按身高递减的顺序加入这排，先向中间人左侧插入，再想中间人右侧插入
 *      5. 身高相同的按名字排序
 * */
using namespace std;
struct info {
    int height;
    string name;
};

bool cmp(const info &a, const info &b) {
    if (a.height != b.height) return a.height < b.height;
    return a.name > b.name;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<info> arr(n);
    vector<vector<string>> ans;
    for (int i = 0; i < n; ++i)
        cin >> arr[i].name >> arr[i].height;
    sort(arr.begin(), arr.end(), cmp);
    int m = n / k;  // 每排m个人
    // 每排
    for (int i = 0; i < k; ++i) {
        int l = i * m, r = (i + 1) * m - 1;
        if (i == k - 1) r = n - 1;
        int len = r - l + 1;
        vector<string> row(len);
        int mid = len / 2;
        row[mid] = arr[r--].name;
        int midl = mid - 1, midr = mid + 1;
        while (r >= l) {
            row[midl--] = arr[r--].name;
            if (r >= l)
                row[midr++] = arr[r--].name;
        }
        ans.push_back(row);
    }
    for (int i = k - 1; i >= 0; --i) {
        int len = ans[i].size();
        for (int j = 0; j < len; ++j) {
            cout << ans[i][j];
            if (j < len - 1) cout << " ";
        }
        cout << "\n";
    }

}
