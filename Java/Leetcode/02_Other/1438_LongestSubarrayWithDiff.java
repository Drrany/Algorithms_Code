
class LongestSubarrayWithDiff {

    public static int longestSubarray(int[] nums, int limit) {

        int minind = 0, count = 0;
        if (nums.length <= 1)
            return 1;
        for (int i = 1; i < nums.length; i++) {
            for (int j = i - 1; j >= minind; j--) {
                if (nums[i] == nums[j])
                    break;
                if (Math.abs(nums[j] - nums[i]) > limit) {
                    minind = j + 1;
                    break;
                }
            }

            count = Math.max(count, i - minind + 1);
        }

        return count;
    }

}