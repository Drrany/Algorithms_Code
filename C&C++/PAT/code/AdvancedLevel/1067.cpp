// 重做
#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 100001;
int arr[MAXSIZE];

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (i != arr[i] && i != 0)
            count++;
    }

    int times = 0;
    int k = 1;    // 目前序列中，不在本位上的最小下标（初始假设为1）
    while (count > 0) {
        if (arr[0] == 0) {  // 若0在0号位置上
            for (int i = k; i < n; ++i) { // 找一个不在本位上的数，和0交换位置
                if (arr[i] != i) {
                    swap(arr[0], arr[i]);
                    times++;
                    k = i;
                    break;
                }
            }
        }
        while (arr[0] != 0) {
            // 找到i号位置的数i所在位置
            swap(arr[0], arr[arr[0]]);
            count--;
            times++;
        }
    }
    cout << times;

}