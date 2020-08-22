#include <vector>
using namespace std;

class Solution
{
public:
    void Merge(vector<int> &arr, int left, int mid, int right) // 将排好序的两段元素[left,mid]和[mid+1,right]合并
    {

        int *copy = new int[right - left + 1];
        int i = left, j = mid + 1, index = 0;
        while (index < right - left + 1)
        {
            if (i > mid || (j <= right && arr[i] >= arr[j]))
                copy[index++] = arr[j++];
            else
                copy[index++] = arr[i++];
        }

        for (int k = left; k <= right; k++)
            arr[k] = copy[k - left];
    }

    void MergeSort(vector<int> &arr, int left, int right)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;
            MergeSort(arr, left, mid);
            MergeSort(arr, mid + 1, right);
            Merge(arr, left, mid, right);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        MergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};