

class NumArray {

    int[] nums;
    int[] sum;

    public NumArray(int[] nums) {
        this.nums = nums;
        this.sum = new int[nums.length + 1];
        this.sum[0] = 0;
        for (int i = 1; i <= nums.length; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
    }

    public int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
}