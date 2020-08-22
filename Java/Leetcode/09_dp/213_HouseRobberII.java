
class HouseRobberII {

    public static int rob(int[] nums) {

        int len = nums.length;
        if (len < 1)
            return 0;
        if (len == 1)
            return nums[0];

        int[] dpwithout1 = new int[len];
        dpwithout1[0] = 0;
        dpwithout1[1] = nums[1];
        for (int i = 2; i < len; i++)
            dpwithout1[i] = Math.max(dpwithout1[i - 2] + nums[i], dpwithout1[i - 1]);

        int[] dpwithoutn = new int[len];
        dpwithoutn[0] = 0;
        dpwithoutn[1] = nums[0];
        for (int i = 2; i < len; i++) {
            dpwithoutn[i] = Math.max(dpwithoutn[i - 2] + nums[i - 1], dpwithoutn[i - 1]);
        }

        return Math.max(dpwithout1[len - 1], dpwithoutn[len - 1]);
    }

    public static int rob2(int[] nums) {

        int len = nums.length;
        if (len < 1)
            return 0;
        if (len == 1)
            return nums[0];

        int max1 = nums[1];
        int max2 = nums[0];

        int ppre1 = 0;
        int pre1 = nums[1];
        for (int i = 2; i < len; i++) {
            max1 = Math.max(ppre1 + nums[i], pre1);
            int tmp = pre1;
            pre1 = max1;
            ppre1 = tmp;
        }

        int ppre2 = 0;
        int pre2 = nums[0];
        for (int i = 2; i < len; i++) {
            max2 = Math.max(ppre2 + nums[i - 1], pre2);
            int tmp = pre2;
            pre2 = max2;
            ppre2 = tmp;
        }

        return Math.max(max1, max2);
    }

}