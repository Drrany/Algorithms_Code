

class IntegerBreak {

    public static int integerBreak(int n) {
        if (n <= 3)
            return n - 1;

        int[] dp = new int[n + 1];
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j < i; j++) {
                dp[i] = Math.max(dp[j] * dp[i - j], dp[i]);
            }
        }

        return dp[n];

    }

}