

class BuySellStockwithTransactionFee {

    public static int maxProfit(int[] prices, int fee) {

        int len = prices.length;
        int dp0 = 0;
        int dp1 = -50001;
        // dp0[i]表示第i天手中无股票时的最大利润
        // dp1[i]表示第i天手中持股票时的最大利润

        for (int i = 0; i < len; i++) {
            int predp0 = dp0;
            dp0 = Math.max(dp0, dp1 + prices[i] - fee);
            dp1 = Math.max(dp1, predp0 - prices[i]);
        }

        return dp0;
    }

}