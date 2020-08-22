

class WiggleSubsequence {

    public static int wiggleMaxLength(int[] nums) {
        int len = nums.length;
        if (len < 2)
            return len;

        int down = 0, up = 0;
        for (int i = 1; i < len; i++) {

            if (nums[i] < nums[i - 1])
                down = up + 1;
            else if (nums[i] > nums[i - 1])
                up = down + 1;

        }

        return Math.max(down, up) + 1;
    }

}