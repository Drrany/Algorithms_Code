

class LongestPalindrome {
    public int longestPalindrome(String s) {

        char[] times = new char[58];
        int sum = 0;

        int len = s.length();
        for (int i = 0; i < len; i++) {
            int index = s.charAt(i) - 'A';
            times[index]++;
            if ((times[index] & 1) == 0)
                sum += 2;
        }

        if (sum < len)
            sum++;

        return sum;

    }

}