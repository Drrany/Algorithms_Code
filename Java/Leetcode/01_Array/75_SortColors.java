package Leetcode;

class SortColors{

    public static void sortColors(int[] nums) {

        if (nums == null || nums.length < 2)
            return;

        int len = nums.length;
        int zero_pos = 0;
        int i = 0;
        int two_pos = len;

        while (i < two_pos) {

            if (nums[i] == 0) {
                int tmp = nums[zero_pos];
                nums[zero_pos++] = 0;
                nums[i] = tmp;
                i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                int tmp = nums[--two_pos];
                nums[two_pos] = 2;
                nums[i] = tmp;
            }
        }

    }

}
