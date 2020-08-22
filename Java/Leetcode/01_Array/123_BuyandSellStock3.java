package Leetcode;

class BuySellThree {

    public int maxProfit(int[] prices) {

        int len = prices.length;
        if (len < 1)
            return 0;

        int dp00 = 0, dp01 = Integer.MIN_VALUE, dp10 = 0, dp11 = Integer.MIN_VALUE;
        
        for (int i = 0; i < len; i++) {
            dp00 = Math.max(dp00, dp01 + prices[i]);
            dp01 = Math.max(dp01, dp10 - prices[i]);

            dp10 = Math.max(dp10, dp11 + prices[i]);
            dp11 = Math.max(dp11, -prices[i]);
        }



        return dp00;

    }

}
