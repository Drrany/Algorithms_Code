

class StoneGame {

    
    public boolean stoneGame(int[] piles) {

        int len = piles.length;
        int[][][] dp = new int[len][len][2];
        // dp[i][j]表示对于 piles[i...j] 这部分石头堆
        // dp[i][j][0]表示表示对于 piles[i...j] 这部分石头堆 先手能获得的最多石子数

        // base case
        for (int i = 0; i < len; i++) {
            dp[i][i][0] = piles[i];
            dp[i][i][1] = 0;
        }

        /*
         * 状态转移方程： 1. 对于先手：dp[i][j].fir = max(piles[i] + dp[i+1][j].sec, piles[j] +
         * dp[i][j-1].sec) 解释：我作为先手，面对 piles[i...j] 时，有两种选择： 要么我选择最左边的那一堆石头，然后面对
         * piles[i+1...j] 但是此时轮到对方，相当于我变成了后手； 要么我选择最右边的那一堆石头，然后面对 piles[i...j-1]
         * 但是此时轮到对方，相当于我变成了后手。 2. 对于后手： if 先手选择左边: dp[i][j].sec = dp[i+1][j].fir if
         * 先手选择右边: dp[i][j].sec = dp[i][j-1].fir 解释：我作为后手，要等先手先选择，有两种情况：
         * 如果先手选择了最左边那堆，给我剩下了 piles[i+1...j] 此时轮到我，我变成了先手； 如果先手选择了最右边那堆，给我剩下了
         * piles[i...j-1] 此时轮到我，我变成了先手。
         */

        // 推算 dp[i][j] 时需要用到 dp[i+1][j] 和 dp[i][j-1]
        // 因此需要斜着遍历数组
        for (int k = 2; k <= len; k++) {
            for (int i = 0; i <= len - k; i++) {
                int j = i + k - 1;
                int left = piles[i] + dp[i + 1][j][1];
                int right = piles[j] + dp[i][j - 1][1];
                if (left < right) {
                    dp[i][j][0] = right;
                    dp[i][j][1] = dp[i][j - 1][0];
                } else {
                    dp[i][j][0] = left;
                    dp[i][j][1] = dp[i + 1][j][0];
                }
            }
        }

        return dp[0][len - 1][0] > dp[0][len - 1][1] ? true : false;

    }

}