#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int tmp = 0, ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp = max(tmp + nums[i], nums[i]);
            ans = max(tmp, ans);
        }

        return ans;
    }
};