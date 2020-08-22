package Leetcode;

class BuyandSellFour {

    public static void main(String[] args) {
        int[] prices = { 6, 1, 6, 4, 3, 0, 2 };
        int n = maxProfit(1, prices);
        System.out.println(n);
    }

    public static int maxProfit(int k, int[] prices) {

        int len = prices.length;

        //若k大于天数的一半，则肯定进行不了k次交易，相当于交易次数无限制
        if (k >= len / 2)
            return maxProfit_infi(prices);

        //第-1~k次交易
        int[][] dp = new int[k + 1][2];

        //第0天时，不可能持股，第-1次交易时也不可能持股
        for (int i = 0; i <= k; i++) {
            dp[i][1] = Integer.MIN_VALUE;
        }

        //第1~len天
        for (int i = 0; i < len; i++) {

            //第0~k次交易
            for (int j = 1; j <= k; j++) {

                dp[j][0] = Math.max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = Math.max(dp[j][1], dp[j - 1][0] - prices[i]);
            }

        }

        return dp[k][0];

    }

    public static int maxProfit_infi(int[] prices) {

        int len = prices.length;
        int dp0 = 0, dp1 = Integer.MIN_VALUE;

        for (int i = 0; i < len; i++) {

            dp0 = Math.max(dp0, dp1 + prices[i]);
            dp1 = Math.max(dp1, dp0 - prices[i]);

        }

        return dp0;

    }

}
