#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int RandomizedPartition(vector<int> &arr, int left, int right)
    {
        srand(time(0));
        int base = rand() % (right - left + 1) + left;
        int tmp = arr[left];
        arr[left] = arr[base];
        arr[base] = tmp;
        // 随机选择[left, right]间的一个数，和left位置交换

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

    int findKthLargest(vector<int> &nums, int k)
    {
        return RandomizedSelect(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
};