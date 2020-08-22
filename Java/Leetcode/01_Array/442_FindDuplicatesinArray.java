
import java.util.ArrayList;
import java.util.List;

class FindDuplicatesinArray {

    public static List<Integer> findDuplicates2(int[] nums) {

        List<Integer> ans = new ArrayList<>();
        int len = nums.length;
        for (int i = 0; i < len; i++) {

            int index = Math.abs(nums[i]) - 1;
            if (nums[index] < 0)
                ans.add(Math.abs(nums[i]));
            else
                nums[index] = -nums[index];
        }

        return ans;

    }

    public static List<Integer> findDuplicates(int[] nums) {

        List<Integer> ans = new ArrayList<>();
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            while (nums[nums[i] - 1] != nums[i]) {
                int index = nums[i] - 1;
                int tmp = nums[index];
                nums[index] = nums[i];
                nums[i] = tmp;
            }
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1)
                ans.add(nums[i]);
        }

        return ans;

    }

}