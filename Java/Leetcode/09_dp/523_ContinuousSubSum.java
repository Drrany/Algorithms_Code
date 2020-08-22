
import java.util.HashMap;
import java.util.Map;

class ContinuousSubSum {

    public static void main(String[] args) {
        int[] nums = { 23, 2, 6, 4, 7 };
        boolean b = checkSubarraySum(nums, 0);
        System.out.println(b);
    }

    public static boolean checkSubarraySum2(int[] nums, int k) {

        int len = nums.length;
        if (len < 1)
            return false;

        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, -1);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (k != 0)
                sum %= k;
            if (m.containsKey(sum)) {
                if (i - m.get(sum) >= 2)
                    return true;
            } else
                m.put(sum, i);
        }

        return false;

    }

    public static boolean checkSubarraySum(int[] nums, int k) {

        int len = nums.length;
        if (len < 1)
            return false;

        int[] sum = new int[len + 1];
        sum[0] = 0;
        for (int i = 1; i <= len; i++)
            sum[i] = sum[i - 1] + nums[i - 1];

        for (int i = 0; i <= len - 2; i++) {
            for (int j = i + 2; j <= len; j++) {
                if (k != 0 && (sum[j] - sum[i]) % k == 0)
                    return true;
                else if (k == 0 && sum[j] - sum[i] == k)
                    return true;
            }
        }

        return false;

    }

}