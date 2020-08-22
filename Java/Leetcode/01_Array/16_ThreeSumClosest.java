
import java.util.Arrays;

class SumClosest {

    public static void main(String[] args) {
        int[] nums = { 1, 1, 1, 0 };
        int target = -100;
        int c = threeSumClosest(nums, target);
        System.out.println(c);

    }

    public static int threeSumClosest(int[] nums, int target) {

        int ans = 0;
        for (int i = 0; i < nums.length && i < 3; i++) {
            ans += nums[i];
        }

        Arrays.sort(nums);

        for (int k = 0; k < nums.length - 2; k++) {

            int i = k + 1;
            int j = nums.length - 1;

            while (i < j) {
                int tmp = nums[k] + nums[i] + nums[j];

                if (tmp == target)
                    return target;
                else if ((Math.abs(tmp - target) < Math.abs(ans - target)))
                    ans = tmp;
                if (tmp < target)
                    i++;
                else
                    j--;
            }

        }

        return ans;
    }
}