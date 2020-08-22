
import java.util.HashMap;
import java.util.Map;

//滑动窗口

class Solution {
    public int lengthOfLongestSubstring(String s) {

        int max = 0, start = 0, end = 0;

        Map<Character, Integer> mp = new HashMap<>();

        while (end < s.length()) {

            if (mp.containsKey(s.charAt(end))) {
                start = Math.max(mp.get(s.charAt(end)), start);
            }
            mp.put(s.charAt(end), end + 1);
            end++;
            max = Math.max((end - start), max);

        }

        return max;
    }
}