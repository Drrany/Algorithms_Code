

import java.util.List;
import java.util.ArrayList;

import java.util.Map;
import java.util.HashMap;

class GroupPeople {

    public List<List<Integer>> groupThePeople(int[] groupSizes) {

        int len = groupSizes.length;
        List<List<Integer>> ans = new ArrayList<>();

        Map<Integer, List<Integer>> m = new HashMap<>();
        for (int i = 0; i < len; i++) {
            if (!m.containsKey(groupSizes[i]))
                m.put(groupSizes[i], new ArrayList<Integer>());

            List<Integer> tmp = m.get(groupSizes[i]);
            tmp.add(i);
            if (tmp.size() == groupSizes[i]) {
                ans.add(tmp);
                m.remove(groupSizes[i]);
            }
        }

        return ans;
    }
    
}