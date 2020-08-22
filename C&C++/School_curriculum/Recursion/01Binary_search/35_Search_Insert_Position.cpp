#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) >>1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<int> list;
    list.push_back(1);
    list.push_back(3);
    list.push_back(5);
    list.push_back(6);
    int index = s.searchInsert(list, 7);
    cout << index;
}