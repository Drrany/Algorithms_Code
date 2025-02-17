

class CombinationSumIV {

    public static int combinationSum4(int[] nums, int target) {

        int len = nums.length;
        int[] dp = new int[target + 1];
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < len; j++) {
                if (i >= nums[j])
                    dp[i] += dp[i - nums[j]];
            }
        }
        
        return dp[target]; 
    }

}