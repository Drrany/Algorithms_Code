

class LongestPalindromicSubsequence {

    public int longestPalindromeSubseq(String s) {

        int len = s.length();
        int[][] dp = new int[len][len];
        for (int i = 0; i < len; i++)
            dp[i][i] = 1;

        // dp[j][i]表示j到i的子串中的最长回文子序列
        for (int i = 1; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (s.charAt(j) == s.charAt(i))
                    dp[j][i] = dp[j + 1][i - 1] + 2;
                else
                    dp[j][i] = Math.max(dp[j + 1][i], dp[j][i - 1]);
            }
        }

        return dp[0][len - 1];

    }

}