package Leetcode;

class MaxProduct {

    public int maxProduct(int[] nums) {

        int len = nums.length;
        int pro = nums[0];
        int imax = 1;
        int imin = 1;

        for (int i = 0; i < len; i++) {
            
            if (nums[i] < 0) {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = Math.max(nums[i], imax * nums[i]);
            imin = Math.min(nums[i], imin * nums[i]);
            
            pro = Math.max(pro, imax);

        }

        return pro;

    }

}
