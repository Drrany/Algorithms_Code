

class SellStockwithCooldown {

    public int maxProfit(int[] prices) {

        int len = prices.length;

        int dp_1 = Integer.MIN_VALUE;
        int dp_0 = 0;
        int pre_dp_0 = 0;

        for (int i = 0; i < len; i++) {
            int tmp = dp_0;
            dp_0 = Math.max(dp_0, dp_1 + prices[i]);
            dp_1 = Math.max(dp_1, pre_dp_0 - prices[i]);
            pre_dp_0 = tmp;
        }

        return dp_0;
    }

}