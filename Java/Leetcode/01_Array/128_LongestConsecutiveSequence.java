package Leetcode;

import java.util.HashSet;
import java.util.Set;

class LongestSeq {

    public int longestConsecutive(int[] nums) {

        int ans = 0;
        int len = nums.length;

        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < len; i++) {
            s.add(nums[i]);
        }

        for (int i = 0; i < len; i++) {
            int tmp = 1;
            int num = nums[i];
            if (!s.contains(num - 1)) {
                while (s.contains(++num))
                    tmp++;
            }
            ans = Math.max(tmp, ans);
        }

        return ans;

    }

}
