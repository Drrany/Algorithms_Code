


class HouseRobber{

    public int rob(int[] nums) {

        int len = nums.length;
        if (len < 1)
            return 0;

        int[] dp = new int[len];
        dp[0] = nums[0];
        /*
         * 状态转移方程： dp[n]=max(dp[n-2]+nums[n],dp[n-1]);
         */

        for (int i = 1; i < len; i++) {
            if (i == 1)
                dp[i] = Math.max(nums[i], dp[i - 1]);
            else
                dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[len - 1];

    }
}
