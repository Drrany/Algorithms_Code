
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Three {
    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(nums);//数组排序
        int i, j;
        for (int k = 0; (k <= nums.length - 3) && nums[k] <= 0; k++) {

            i = k + 1;
            j = nums.length - 1;
            if (k > 0 && nums[k] == nums[k - 1])
                continue;

            while (i < j) {

                int num = nums[k] + nums[i] + nums[j];

                if (num == 0)
                    ans.add(new ArrayList<Integer>(Arrays.asList(nums[k], nums[i], nums[j])));

                if (num < 0 || num == 0) {
                    do {
                        i++;
                    } while (i < j && nums[i] == nums[i - 1]);
                }

                if (num > 0 || num == 0) {
                    do {
                        j--;
                    } while (i < j && nums[j] == nums[j + 1]);
                }

            }

        }

        return ans;

    }
}