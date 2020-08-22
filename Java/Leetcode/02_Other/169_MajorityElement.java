

import java.util.HashMap;
import java.util.Map;

class MajorityElement {

    // 一、哈希表
    public int majorityElement(int[] nums) {

        int len = nums.length;
        Map<Integer, Integer> times = new HashMap<>();

        for (int i = 0; i < len; i++) {
            int count = times.getOrDefault(nums[i], 0) + 1;
            times.put(nums[i], count);

            if (count > (len / 2))
                return nums[i];
        }

        return 0;

    }

    // 二、摩尔投票法
    public int majorityElement2(int[] nums) {

        int count = 1;
        int num = nums[0];

        for (int i = 1; i < nums.length; i++) {

            if (num == nums[i])
                count++;
            else {
                count--;
                if (count <= 0) {
                    num = nums[i];
                    count = 1;
                }
            }

        }

        return num;

    }

}
