

class TargetSum {

    // 方法2：动态规划
    public int findTargetSumWays2(int[] nums, int S) {

        // dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]
        // 表示前i个数组合为j的方案数

        int len = nums.length;
        int[][] dp = new int[2][2001];
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;

        for (int i = 1; i < len; i++) {
            dp[1] = new int[2001];
            for (int m = -1000; m <= 1000; m++) {
                if (dp[0][m + 1000] > 0) {
                    dp[1][m + nums[i] + 1000] += dp[0][m + 1000];
                    dp[1][m - nums[i] + 1000] += dp[0][m + 1000];
                }
            }
            dp[0] = dp[1];
        }

        return S > 1000 ? 0 : dp[0][S + 1000];
    }

    // 方法1：递归，耗时长

    static int ans;

    public int findTargetSumWays(int[] nums, int S) {

        ans = 0;
        reCur(nums, S, 0, nums.length);
        return ans;
    }

    public static void reCur(int[] nums, int res, int i, int len) {

        if (res == 0 && i == len)
            ans++;
        if (i >= len)
            return;

        reCur(nums, res - nums[i], i + 1, len);
        reCur(nums, res + nums[i], i + 1, len);

    }

}