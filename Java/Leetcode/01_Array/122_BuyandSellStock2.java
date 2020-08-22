package Leetcode;

class BuySellTwo {

    public int maxProfit(int[] prices) {

        int len = prices.length;
        if (len < 1)
            return 0;

        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < len; i++) {

            dp0 = Math.max(dp0, dp1 + prices[i]);
            dp1 = Math.max(dp1, dp0 - prices[i]);

        }

        return dp0;

    }

    public int maxProfit1(int[] prices) {

        int len = prices.length;
        int profit = 0, tmp = 0;

        for (int i = 1; i < len; i++) {

            tmp = prices[i] - prices[i - 1];
            if (tmp > 0)
                profit += tmp;

        }

        return profit;

    }

}
