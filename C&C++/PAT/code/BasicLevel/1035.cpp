#include <bits/stdc++.h>

using namespace std;

bool isEqual(int *a, int *b, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i < n - 1)
            cout << " ";
    }
}

bool isInsertSort(int *ori, int *target, int n) {
    bool isInsert = false;
    int g = 0;
    for (int i = 2; i <= n; ++i) {
        sort(ori, ori + i);
        if (isEqual(target, ori, n))    // 相等，再进行一轮然后输出
        {
            isInsert = true;
            g = i;
            break;
        }
    }
    if (isInsert) {
        cout << "Insertion Sort" << endl;
        sort(ori, ori + min(g + 1, n));
        printArray(ori, n);
        return true;
    }
    return false;
}

void mergeSort(int *ori, int *target, int n) {
    cout << "Merge Sort" << endl;
    bool flag = false;
    for (int gap = 2; gap / 2 <= n; gap *= 2) {
        if (gap != 2 && isEqual(ori, target, n))
            flag = true;
        for (int i = 0; i < n; i += gap)
            sort(ori + i, ori + min(n, i + gap));
        if (flag) {
            printArray(ori, n);
            return;
        }
    }
}

int main() {
    int n;
    int *ori1 = new int[n];
    int *ori2 = new int[n];
    int *arr = new int[n];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ori1[i];
        ori2[i] = ori1[i];
    }
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // 模仿插入排序
    if (!isInsertSort(ori1, arr, n))
        mergeSort(ori2, arr, n);
}