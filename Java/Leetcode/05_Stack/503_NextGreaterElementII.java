
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
class NextGreaterElementII {

    public int[] nextGreaterElements(int[] nums) {

        int len = nums.length;
        int[] ans = new int[len];
        Deque<Integer> s = new LinkedList<>();

        for (int i = 2 * len - 1; i >= 0; i--) {
            while (!s.isEmpty() && nums[s.peek()] <= nums[i % len])
                s.pop();
            ans[i % len] = s.isEmpty() ? -1 : nums[s.peek()];
            s.push(i % len);
        }

        return ans;

    }

    public int[] nextGreaterElement1(int[] nums1, int[] nums2) {

        int len1 = nums1.length;
        int[] ans = new int[len1];
        Deque<Integer> s = new LinkedList<>();
        Map<Integer, Integer> m = new HashMap<>();

        for (int i = 0; i < nums2.length; i++) {
            while (!s.isEmpty() && nums2[s.peek()] < nums2[i])
                m.put(nums2[s.pop()], i);
            s.push(i);
        }

        for (int i = 0; i < len1; i++)
            ans[i] = m.containsKey(nums1[i]) ? nums2[m.get(nums1[i])] : -1;

        return ans;
    }


}