
class RotatedTwo {

    public boolean search(int[] nums, int target) {

        int len = nums.length;
        int left = 0, right = len - 1;
        while (left <= right) {

            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[left]==nums[mid]) {
                left++;
                continue;
            }

            if (nums[0] < nums[mid] && target >= nums[0] && target < nums[mid])
                right = mid - 1;

            else if (nums[0] >= nums[mid] && target < nums[mid])
                right = mid - 1;

            else if (nums[0] >= nums[mid] && target >= nums[0])
                right = mid - 1;

            else
                left = mid + 1;
        }

        return false;

    }

}
