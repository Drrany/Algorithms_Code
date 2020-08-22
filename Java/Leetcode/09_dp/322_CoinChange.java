
import java.util.Arrays;

class CoinChange {

    public static int coinChange2(int[] coins, int amount) {

        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE - 1);
        dp[0] = 0;

        for (int i = 0; i <= amount; i++) {

            for (int n : coins) {
                if (i < n)
                    continue;
                dp[i] = Math.min(dp[i], dp[i - n] + 1);
            }

        }

        return (dp[amount] == Integer.MAX_VALUE - 1) ? -1 : dp[amount];

    }

}