
class JumpGame {

    public static void main(String[] args) {
        int[] nums = { 5, 4, 3, 2, 1, 1 };
        int n = jump(nums);
        System.out.println(n);
    }
    
    public static int jump2(int[] nums) {

        int len = nums.length;
        int i = 0, count = 0;

        while (i + nums[i] < len - 1) {

            count++;
            int max = 0, index = i;
            for (int j = 1; j <= nums[i] && i + j < len; j++) {
                if (j + nums[i + j] > max) {
                    max = j + nums[i + j];
                    index = i + j;
                }
            }
            i = index;
        }

        count = i < len - 1 ? count + 1 : count;

        return count;
    }

    public static int jump(int[] nums) {

        int step = 0;
        int index = 0;
        int len = nums.length;

        if (len <= 1) {
            return 0;
        }

        while (index + nums[index] < len - 1) {

            int max = 0;
            int next = 0;

            for (int j = 0; j <= nums[index]; j++) {

                int tmp = nums[index + j] + j;
                if (nums[index + j] != 0 && tmp > max) {
                    max = tmp;
                    next = j;
                }

            }

            step++;
            index += next;

        }

        return step+1;

    }
}