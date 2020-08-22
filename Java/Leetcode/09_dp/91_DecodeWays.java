
class DecodeWays {

    public static void main(String[] args) {
        numDecodings("101");
    }

    public static int numDecodings(String s) {
        int len = s.length();
        if (len < 1 || s.charAt(0) == '0')
            return 0;

        int[] dp = new int[len + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < len; i++) {
            if (s.charAt(i) == '0') {
                if (s.charAt(i - 1) != '1' && s.charAt(i - 1) != '2')
                    return 0;
                dp[i + 1] = dp[i - 1];
            } else if (s.charAt(i - 1) == '1' || (s.charAt(i - 1) == '2' && s.charAt(i) <= '6'))
                dp[i + 1] = dp[i] + dp[i - 1];
            else
                dp[i + 1] = dp[i];
        }

        return dp[len];
    }
}