
import java.util.ArrayList;
import java.util.List;


class FindNumDisapinArray {

    public List<Integer> findDisappearedNumbers(int[] nums) {

        List<Integer> ans = new ArrayList<>();

        int len = nums.length;

        // 将每个元素对应的索引位置元素 加上 len-1
        for (int i = 0; i < len; i++) {
            int index = (nums[i] - 1) % len;
            nums[index] += len;
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] <= len)
                ans.add(i + 1);
        }

        return ans;

    }

}