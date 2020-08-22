
import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;


class CountNiceSubarrays {

     // 方法一：双指针
     public static int numberOfSubarrays2(int[] nums, int k) {

        List<Integer> odd = new ArrayList<>();
        int len = nums.length;
        int count = 0;
        odd.add(-1);
        for (int i = 0; i < len; i++) {
            if ((nums[i] & 1) == 1)
                odd.add(i);
        }
        odd.add(len);
        int i = 1, j = i + k - 1;
        int size = odd.size();
        while (i < size - 1 && j < size - 1) {

            int left = odd.get(i) - odd.get(i - 1);
            int right = odd.get(j + 1) - odd.get(j);
            count = count + left * right;
            i++;
            j = i + k - 1;

        }

        return count;
    }

    // 方法二：前缀和+哈希表
    public static int numberOfSubarrays(int[] nums, int k) {

        int len = nums.length;
        int sum = 0, count = 0;

        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, 1);
        for (int i = 0; i < len; i++) {
            sum += nums[i] & 1;
            if (m.containsKey(sum - k))
                count += m.get(sum - k);
            m.put(sum, m.getOrDefault(sum, 0) + 1);
        }

        return count;

    }
    
}