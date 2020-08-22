
import java.util.HashMap;
import java.util.Map;

//暴力法
class SolutionOne {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }
}


//哈希表一次遍历
class SolutionTwo {
    public int[] twoSum(int[] nums, int target) {

        Map<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {

            int discre = target - nums[i];

            if (mp.containsKey(discre)) {
                return new int[] { mp.get(discre), i };
            }

            mp.put(nums[i], i);
        }

        throw new IllegalArgumentException("No two sum solution");
    }
}