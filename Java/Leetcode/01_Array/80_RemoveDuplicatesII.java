package Leetcode;

class RemoveTwo {

    public int removeDuplicates(int[] nums) {

        int len = nums.length;
        if (len < 3)
            return len;

        int fast = 2, slow = 1;
        while (fast < len) {

            if (nums[fast] > nums[slow - 1]) {
                nums[++slow] = nums[fast];
            }
            fast++;

        }

        return slow + 1;
    }

}
