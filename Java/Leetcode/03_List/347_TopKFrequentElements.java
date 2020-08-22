
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


class TopKFrequentElements {

    public List<Integer> topKFrequent(int[] nums, int k) {

        List<Integer> ans = new ArrayList<>();

        int len = nums.length;
        Map<Integer, Integer> count = new HashMap<>();
        for (int i = 0; i < len; i++) {
            count.put(nums[i], count.getOrDefault(nums[i], 0) + 1);
        }

        List<Integer>[] barrel = new List[len + 1];
        for (Integer n : count.keySet()) {
            int co = count.get(n);
            if (barrel[co] == null)
                barrel[co] = new ArrayList<>();
            barrel[co].add(n);
        }

        for (int i = len; i >= 0 && k > 0; i--) {
            if (barrel[i] != null){
                ans.addAll(barrel[i]);
                k -= barrel[i].size();
            }
        }

        return ans;

    }

}