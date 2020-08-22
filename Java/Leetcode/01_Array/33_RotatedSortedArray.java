package Leetcode;

class Rotated {

    public int search(int[] nums, int target) {

        int left = 0, right = nums.length - 1;
 
        while (left <= right) {

            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[0] <= nums[mid] && target >= nums[0] && target < nums[mid])
                right = mid - 1;

            else if (nums[0] > nums[mid] && target < nums[mid])
                right = mid - 1;

            else if (nums[0] > nums[mid] && target >= nums[0])
                right = mid - 1;

            else
                left = mid + 1;

        }

        return -1;

    }

}