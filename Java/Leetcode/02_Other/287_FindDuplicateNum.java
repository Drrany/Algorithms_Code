

class FindDuplicateNum {

    public static int findDuplicate(int[] nums) {

        int slow = 0, fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        int finder = 0;
        while (true) {
            finder = nums[finder];
            slow = nums[slow];
            if (slow == finder)
                return slow;
        }

    }

}