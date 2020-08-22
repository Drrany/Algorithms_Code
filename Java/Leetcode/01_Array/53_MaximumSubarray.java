package Leetcode;

class MaxSub {

    public int maxSubArray(int[] nums) {

        int len = nums.length;
        int fn = 0;
        int ans = Integer.MIN_VALUE;

        for (int i = 0; i < len; i++) {

            fn = Math.max(nums[i], fn + nums[i]);
            ans = Math.max(fn, ans);

        }

        return ans;

    }

}