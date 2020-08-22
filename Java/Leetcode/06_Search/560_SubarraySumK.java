
import java.util.HashMap;
import java.util.Map;

class SubarraySumK {

    public int subarraySum(int[] nums, int k) {

        int len = nums.length;
        int sum = 0;
        int count = 0;
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, 1);

        for (int i = 0; i < len; i++) {
            sum += nums[i];
            int target = sum - k;
            if (m.containsKey(target))
                count += m.get(target);
            m.put(sum, m.getOrDefault(sum, 0) + 1);
        }

        return count;
    }

}