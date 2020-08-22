

class MinSizeSubSum {

    public static int minSubArrayLen(int s, int[] nums) {

        int minlen = Integer.MAX_VALUE;
        int sum = 0;
        int len = 0;
        int i = 0;

        while (i < nums.length) {
            if (sum < s) {
                sum += nums[i++];
                len++;
            }

            while (sum >= s) {
                minlen = Math.min(minlen, len);
                sum -= nums[i - len];
                len--;
            }
        }

        return minlen == Integer.MAX_VALUE ? 0 : minlen;

    }

}