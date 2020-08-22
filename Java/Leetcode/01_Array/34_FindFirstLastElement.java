package Leetcode;

class FindFirstLast {

    public int[] searchRange(int[] nums, int target) {

        int[] ans = { -1, -1 };
        int len = nums.length;

        int i = 0, j = len - 1;
        while (i <= j) {

            int mid = (i + j) / 2;
            if (nums[mid] == target) {
                int start = mid;
                int end = mid;
                while (start >= 0 && nums[start] == target)
                    start--;
                while (end <= len - 1 && nums[end] == target)
                    end++;
                ans[0] = start + 1;
                ans[1] = end - 1;
                break;
            } else if (nums[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;

        }

        return ans;

    }

}