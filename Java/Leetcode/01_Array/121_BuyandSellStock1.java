package Leetcode;


class BuyandSellOne {

    public int maxProfit(int[] prices) {

        int len = prices.length;
        if (len < 1)
            return 0;

        int dp0 = 0;
        int dp1 = -prices[0];
        for (int i = 1; i < len; i++) {
            dp0 = Math.max(dp0, dp1 + prices[i]);
            dp1 = Math.max(dp1, -prices[i]);
        }

        return dp0;

    }

    public int maxProfit2(int[] prices) {

        int len = prices.length;
        int profit = 0;
        int minpr = Integer.MAX_VALUE;

        for (int i = 0; i < len; i++) {
            if(prices[i]<minpr)
                minpr = prices[i];
            else 
                profit = Math.max(profit, prices[i] - minpr);
        }

        return profit;

    }

}
