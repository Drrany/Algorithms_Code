package Leetcode;

class Solution {

    public static void main(String[] args) {
        String s = "abbd";
        System.out.println(longestPalindrome1(s));
    }

    // 动态规划法
    public static String longestPalindrome(String s) {

        int len = s.length();
        if (len < 2)
            return s;

        boolean[][] dp = new boolean[len][len];

        int maxlen = 1;
        int start = 0;

        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {

                if (s.charAt(i) == s.charAt(j) && ((i - j) < 3 || dp[j + 1][i - 1]))
                    dp[j][i] = true;

                if (dp[j][i] && maxlen < (i - j + 1)) {
                    maxlen = i - j + 1;
                    start = j;
                }

            }
        }

        return s.substring(start, start + maxlen);

    }

    // 中心扩展法
    public static String longestPalindrome1(String s) {

        if (s.length() < 2)
            return s;

        int left = 0;
        int right = 0;
        int maxlen = 0;

        for (int i = 0; i < s.length(); i++) {
            int odd = expandCenter(s, i, i);
            int even = expandCenter(s, i, i + 1);
            int len = Math.max(odd, even);
            if (len > maxlen) {
                left = i - (len - 1) / 2;
                right = i + len / 2 + 1;
                maxlen = right - left;
            }
        }


        return s.substring(left, right);

    }

    public static int expandCenter(String s, int left, int right) {
        while ((left >= 0 && right < s.length()) && (s.charAt(left) == s.charAt(right))) {
            left--;
            right++;
        }
        return right - left - 1;
    }

}