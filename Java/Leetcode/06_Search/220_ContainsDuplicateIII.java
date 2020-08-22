
import java.util.TreeSet;

class ContainsDuplicateIII {

    
    public static boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {

        int len = nums.length;
        TreeSet<Integer> sw = new TreeSet<>();

        for (int i = 0; i < len; i++) {
            Integer r = sw.ceiling(nums[i]);
            if (r != null && r <= t + nums[i])
                return true;

            r = sw.floor(nums[i]);
            if (r != null && nums[i] <= t + r)
                return true;

            sw.add(nums[i]);
            if (sw.size() > k)
                sw.remove(nums[i - k]);
        }

        return false;

    }

}