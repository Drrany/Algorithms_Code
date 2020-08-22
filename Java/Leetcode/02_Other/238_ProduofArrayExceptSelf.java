


class ProduofArrayExceptSelf {

    public int[] productExceptSelf(int[] nums) {

        int len = nums.length;
        int[] pro = new int[len];

        int presum = 1;
        for (int i = 0; i < len; i++) {
            pro[i] = presum;
            presum *= nums[i];
        }

        int aftersum = 1;
        for (int i = len-1; i >= 0; i--) {
            pro[i] *= aftersum;
            aftersum *= nums[i];
        }

        return pro;

    }

}