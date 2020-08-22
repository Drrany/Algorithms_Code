

class LongestIncrea {

    public static int lengthOfLIS(int[] nums) {

        int len = nums.length;
        if (len < 2)
            return len;
        int[] dp = new int[len];
        int max = 1;

        for (int i = 0; i < len; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
            }
            max = Math.max(max, dp[i]);
        }

        return max;
    }

}