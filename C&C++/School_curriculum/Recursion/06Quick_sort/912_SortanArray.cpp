#include <vector>
using namespace std;

class Solution
{
public:
    int Parition(vector<int> &arr, int left, int right)
    { // 将arr[left]放到合适的位置
        int x = arr[left];
        while (left < right)
        {
            while (arr[right] >= x && left < right)
                right--;
            arr[left] = arr[right];
            while (arr[left] <= x && left < right)
                left++;
            arr[right] = arr[left];
        }
        arr[left] = x;
        return left;
    }

    void QuickSort(vector<int> &arr, int left, int right)
    {
        if (left < right)
        {
            int i = Parition(arr, left, right);
            QuickSort(arr, left, i - 1);
            QuickSort(arr, i + 1, right);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};