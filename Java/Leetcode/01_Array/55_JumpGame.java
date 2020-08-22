package Leetcode;

class Jump {

    public static boolean canJump(int[] nums) {

        int dis = 0;
        int len = nums.length;
        for (int i = 0; i < len; i++) {

            if (dis < i)
                return false;

            dis = Math.max(dis, nums[i] + i);
            if (dis >= len - 1)
                return true;

        }

        return true;

    }

}