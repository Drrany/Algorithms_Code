

class PartitionSubsetSum {

    public boolean canPartition(int[] nums) {

        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        int len = nums.length;
        boolean[] dp = new boolean[target + 1];

        if (nums[0] <= target)
            dp[nums[0]] = true;

        for (int i = 1; i < len; i++) {
            for (int j = target; j >= nums[i]; j--) {

                if (dp[target])
                    return true;

                dp[j] = dp[j] || dp[j - nums[i]];

            }
        }

        return dp[target];

    }

}