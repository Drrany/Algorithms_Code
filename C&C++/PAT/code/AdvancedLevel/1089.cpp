
#include <bits/stdc++.h>

using namespace std;

vector<int> ori, res;

bool isInsert(int n) {
    vector<int> arr(ori);
    // 对[0-i排序]
    for (int i = 2; i <= n; ++i) {
        sort(arr.begin(), arr.begin() + i);
        if (arr == res) {
            sort(res.begin(), res.begin() + i + 1);
            return true;
        }
    }
    return false;
}

void mergeSort(int n) {
    // 每gap个数排序
    for (int gap = 2; gap < n; gap *= 2) {
        for (int i = 0; i < n; i += gap) {
            if (i + gap > n) sort(ori.begin() + i, ori.end());
            else sort(ori.begin() + i, ori.begin() + i + gap);
        }
        if (ori == res) {
            gap *= 2;
            if (gap > n) sort(res.begin(), res.end());
            else {
                for (int i = 0; i < n; i += gap) {
                    if (i + gap > n) sort(res.begin() + i, res.end());
                    else sort(res.begin() + i, res.begin() + i + gap);
                }
            }
        }
    }

}

int main() {
    int n;
    cin >> n;
    ori.resize(n);
    res.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> ori[i];
    for (int i = 0; i < n; ++i)
        cin >> res[i];
    if (isInsert(n))
        cout << "Insertion Sort\n";
    else {
        cout << "Merge Sort\n";
        mergeSort(n);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i];
        if (i < n - 1) cout << " ";
    }
}










