

class PalindromicSubstrings {

    public int countSubstrings(String s) {

        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += countPa(s, i, i);
            count += countPa(s, i, i + 1);
        }

        return count;

    }

    public static int countPa(String s, int left, int right) {
        int ans = 0;
        while (left >= 0 && right < s.length() && s.charAt(left--) == s.charAt(right++))
            ans++;

        return ans;

    }

}