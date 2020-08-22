#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int RandomizedPartition(vector<int> &arr, int left, int right)
{
    srand(time(0));
    int base = rand() % (right - left + 1) + left;
    int tmp = arr[left];
    arr[left] = arr[base];
    arr[base] = tmp;
    // 随机选择[left, right]间的一个数，和left位置上的数交换

    int x = arr[left];

    while (left < right)
    {
        while (left < right && arr[right] >= x) // 在数组右边找第一个小于x的
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= x) // 在数组左边找第一个大于x的
            left++;
        arr[right] = arr[left];
    }
    arr[left] = x;
    return left;
}

int RandomizedSelect(vector<int> &arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];

    int index = RandomizedPartition(arr, left, right); // 划分

    if ((index - left + 1) >= k)
        return RandomizedSelect(arr, left, index, k);
    return RandomizedSelect(arr, index + 1, right, k - (index - left + 1));
}

int main()
{
    vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << RandomizedSelect(arr, 0, arr.size() - 1, 4) << endl;
}